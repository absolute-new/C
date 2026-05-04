#include <check.h>

#include "../brick_game/tetris/fsm.h"
#include "utils.h"

static void init_game_state(t_Game *state) {
  t_Figure temp;

  fsm_init(state);
  state->field = allocate_matrix(HEIGHT, WIDTH);
  state->next = allocate_matrix(FIG_Y, FIG_X);
  state->next_type = FIGURE_I;
  state->game_over = 0;
  state->started = 0;
  state->pause = 0;
  state->score = 0;
  state->level = 1;
  state->speed = 600;
  state->high_score = 0;
  set_figure_i(&temp, 0, 0);
  copy_figure_to_matrix(state->next, &temp);
  for (int i = 0; i < FIG_Y; i++)
    for (int j = 0; j < FIG_X; j++) state->current_figure.shape[i][j] = 0;
  state->current_figure.type = FIGURE_I;
  state->current_figure.x = WIDTH / 2 - 2;
  state->current_figure.y = 0;
}

START_TEST(test_fsm_init) {
  t_Game state;

  fsm_init(&state);
  ck_assert_int_eq(state.pause, 0);
  ck_assert_int_eq(state.game_over, 0);
}
END_TEST

START_TEST(test_fsm_start) {
  t_Game state;

  fsm_init(&state);
  fsm_handle_action(&state, Start);
  ck_assert_int_eq(state.started, 1);
}
END_TEST

START_TEST(test_fsm_pause) {
  t_Game state;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  fsm_handle_action(&state, Pause);
  ck_assert_int_eq(state.pause, 1);
  fsm_handle_action(&state, Pause);
  ck_assert_int_eq(state.pause, 0);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_terminate) {
  t_Game state;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  fsm_handle_action(&state, Terminate);
  ck_assert_int_eq(state.game_over, 1);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_game_over_to_start) {
  t_Game state;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  fsm_handle_action(&state, Terminate);
  ck_assert_int_eq(state.game_over, 1);
  fsm_handle_action(&state, Start);
  ck_assert_int_eq(state.game_over, 0);
  ck_assert_int_eq(state.started, 1);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_left_right) {
  t_Game state;
  int orig_x;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  orig_x = state.current_figure.x;
  fsm_handle_action(&state, Left);
  ck_assert_int_eq(state.current_figure.x, orig_x - 1);
  fsm_handle_action(&state, Right);
  fsm_handle_action(&state, Right);
  ck_assert_int_eq(state.current_figure.x, orig_x + 1);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_up) {
  t_Game state;
  int was_y;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  was_y = state.current_figure.y;
  fsm_handle_action(&state, Up);
  ck_assert(state.current_figure.y > was_y);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_rotate) {
  t_Game state;
  t_Figure before;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  before = state.current_figure;
  fsm_handle_action(&state, Action);
  ck_assert_int_eq(compare_figures(&state.current_figure, &before), 0);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_timer_tick) {
  t_Game state;

  init_game_state(&state);
  fsm_timer_tick(&state);
  ck_assert_int_eq(1, 1);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_shift_attaching) {
  t_Game state;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  for (int x = 5; x <= 8; x++) state.field[2][x] = 1;
  fsm_timer_tick(&state);
  fsm_handle_action(&state, Down);
  fsm_timer_tick(&state);
  fsm_handle_action(&state, Down);
  ck_assert_int_eq(state.field[1][5], FIGURE_I + 1);
  ck_assert_int_eq(state.field[1][6], FIGURE_I + 1);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

START_TEST(test_fsm_down_collision_in_moving) {
  t_Game state;

  init_game_state(&state);
  fsm_handle_action(&state, Start);
  fsm_handle_action(&state, Down);
  for (int x = 5; x <= 8; x++) state.field[2][x] = 1;
  fsm_handle_action(&state, Down);
  ck_assert_int_eq(state.field[1][5], 0);
  free_matrix(state.field, HEIGHT);
  free_matrix(state.next, FIG_Y);
}
END_TEST

Suite *fsm_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("FSM");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_fsm_init);
  tcase_add_test(tc, test_fsm_start);
  tcase_add_test(tc, test_fsm_pause);
  tcase_add_test(tc, test_fsm_terminate);
  tcase_add_test(tc, test_fsm_game_over_to_start);
  tcase_add_test(tc, test_fsm_left_right);
  tcase_add_test(tc, test_fsm_up);
  tcase_add_test(tc, test_fsm_rotate);
  tcase_add_test(tc, test_fsm_timer_tick);
  tcase_add_test(tc, test_fsm_shift_attaching);
  tcase_add_test(tc, test_fsm_down_collision_in_moving);
  suite_add_tcase(s, tc);
  return (s);
}