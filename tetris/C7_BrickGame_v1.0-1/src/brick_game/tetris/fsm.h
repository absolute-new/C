/**
 * @file fsm.h
 * @brief Конечный автомат игры Tetris
 */
#ifndef FSM_H
# define FSM_H

# include "tetris.h"

/**
 * @brief Состояния КА
 */
typedef enum game_state
{
	STATE_START,		/**< Ожидание кнопки старт */
	STATE_SPAWN,		/**< Создание новой фигуры */
	STATE_MOVING,		/**< Обработка действий пользователя */
	STATE_SHIFT,		/**< Движение вниз по таймеру */
	STATE_ATTACHING,	/**< Прилипание и удаление линий */
	STATE_GAME_OVER		/**< Конец игры */
}   t_GameState;

void	fsm_init(t_Game *state);
void	fsm_timer_tick(t_Game *state);
void	fsm_handle_action(t_Game *state, t_UserAction action);

#endif