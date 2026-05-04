/**
 * @file fsm.c
 * @brief Реализация механики КА
 */

#include "fsm.h"

#include <stdlib.h>

static t_GameState g_fsm_state = STATE_START;

/* Function prototypes */
static void handle_start_state(t_Game *state, t_UserAction action);
static void handle_spawn_state(t_Game *state);
static void handle_moving_state(t_Game *state, t_UserAction action);
static void handle_shift_state(t_Game *state);
static void handle_attaching_state(t_Game *state);
static void handle_game_over_state(t_Game *state, t_UserAction action);

/**
 * @brief Обработка состояния START: ожидание нажатия кнопки Start.
 * @param state Указатель на состояние игры.
 * @param action Действия пользователя.
 */
static void handle_start_state(t_Game *state, t_UserAction action) {
  if (action == Start) {
    game_init();
    state->started = 1;
    g_fsm_state = STATE_SPAWN;
  }
}

/**
 * @brief Обработка состояния SPAWN: создание новой фигуры.
 * @param state Указатель на состояние игры.
 */
static void handle_spawn_state(t_Game *state) {
  if (!state->next[0][0]) generate_random_figure(state->next, state->next_type);
  if (!spawn_figure(state->field, state->next, &state->current_figure,
                    &state->game_over, &state->next_type))
    g_fsm_state = STATE_GAME_OVER;
  else
    g_fsm_state = STATE_MOVING;
}

/**
 * @brief Обработка состояния MOVING: действие игрока.
 * @param state Указатель на состояние игры.
 * @param action Действие пользователя.
 */
static void handle_moving_state(t_Game *state, t_UserAction action) {
  switch (action) {
    case Left:
      try_move(state->field, &state->current_figure, -1, 0);
      break;
    case Right:
      try_move(state->field, &state->current_figure, 1, 0);
      break;
    case Down:
      if (!try_move(state->field, &state->current_figure, 0, 1))
        g_fsm_state = STATE_ATTACHING;
      break;
    case Up:
      while (try_move(state->field, &state->current_figure, 0, 1));
      g_fsm_state = STATE_ATTACHING;
      break;
    case Action:
      try_rotate(state->field, &state->current_figure);
      break;
    case Pause:
      state->pause = !state->pause;
      break;
    case Terminate:
      state->game_over = 1;
      g_fsm_state = STATE_GAME_OVER;
      break;
    default:
      break;
  }
}

/**
 * @brief Обработка состояния SHIFT: Движение вниз по таймеру.
 * @param state Указатель на состояние игры.
 */
static void handle_shift_state(t_Game *state) {
  if (!try_move(state->field, &state->current_figure, 0, 1))
    g_fsm_state = STATE_ATTACHING;
  else
    g_fsm_state = STATE_MOVING;
}

/**
 * @brief Обработка состояния ATTACHING: прилипание фигуры и удаление линий.
 * @param state Указатель на состояние игры.
 */
static void handle_attaching_state(t_Game *state) {
  attach_figure(state->field, &state->current_figure);
  clear_lines(state->field, &state->score, &state->level, &state->speed);
  g_fsm_state = STATE_SPAWN;
  handle_spawn_state(state);
}

/**
 * @brief Обработка состояния GAME_OVER: конец игры.
 * @param state Указатель на состояние игры.
 * @param action Действие пользователя.
 */
static void handle_game_over_state(t_Game *state, t_UserAction action) {
  if (action == Start) {
    game_init();
    state->game_over = 0;
    state->started = 1;
    g_fsm_state = STATE_SPAWN;
  } else if (action == Terminate) {
    game_destroy();
    exit(0);
  }
}

/**
 * @brief Обработка действий пользователя и переход состояний игры.
 * @param state Указатель на состояние игры.
 * @param action Действие пользователя.
 */
void fsm_handle_action(t_Game *state, t_UserAction action) {
  if (state->pause) {
    if (action == Pause) state->pause = 0;
    return;
  }
  switch (g_fsm_state) {
    case STATE_START:
      handle_start_state(state, action);
      break;
    case STATE_SPAWN:
      handle_spawn_state(state);
      break;
    case STATE_MOVING:
      handle_moving_state(state, action);
      break;
    case STATE_SHIFT:
      handle_shift_state(state);
      break;
    case STATE_ATTACHING:
      handle_attaching_state(state);
      break;
    case STATE_GAME_OVER:
      handle_game_over_state(state, action);
      break;
    default:
      break;
  }
}

/**
 * @brief Инициализация состояния игры.
 * @param state Указатель на состояние игры.
 */
void fsm_init(t_Game *state) {
  g_fsm_state = STATE_START;
  state->pause = 0;
  state->game_over = 0;
}

/**
 * @brief Таймер падения, перехода в состояние SHIFT: движение вниз по таймеру.
 * @param state Указатель на состояние игры.
 */
void fsm_timer_tick(t_Game *state) {
  if (state->pause) {
    return;
  }
  if (g_fsm_state == STATE_MOVING) {
    g_fsm_state = STATE_SHIFT;
  }
}
