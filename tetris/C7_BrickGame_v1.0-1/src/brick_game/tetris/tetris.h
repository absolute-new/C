/**
 * @file tetris.h
 * @brief Игра Тетрис.
 */

#ifndef TETRIS_H
# define TETRIS_H

# include <stdbool.h>
# include <pthread.h>
# include "memory.h"
# include "figure.h"
# include "game_logic.h"

# define QUEUE_SIZE	32	/**< Размер очереди действий. */

/**
 * @brief Действия пользователя.
 */
typedef enum userAction
{
	Start,		/**< Начать игру. */
	Pause,		/**< Пауза. */
	Terminate,	/**< Завершить игру. */
	Left,		/**< Движение влево. */
	Right,		/**< Движение вправо. */
	Up,			/**< Хард-дроп. */
	Down,		/**< Движение вниз. */
	Action		/**< Поворот фигуры. */
}	t_UserAction;

/**
 * @brief Информация состояния игры для отрисовки.
 */
typedef struct gameInfo
{
	int	**field;	/**< Игровое поле. */
	int	**next;		/**< Следующая фигура. */
	int	score;		/**< Текущий счёт. */
	int	high_score;	/**< Рекордный счёт. */
	int	level;		/**< Текущий уровень. */
	int	speed;		/**< Скорость падения(мс). */
	int	pause;		/**< Флаг паузы. */
}	t_GameInfo;

/**
 * @brief Основное состояние игры.
 */
typedef struct game
{
	int				**field;		/**< Игровое поле. */
	int				**next;			/**< Следующая фигура. */
	int				score;			/**< Текущий счёт. */
	int				high_score;		/**< Рекордный счёт. */
	int				level;			/**< Текущий уровень. */
	int				speed;			/**< Скорость падения(мс). */
	int				pause;			/**< Флаг паузы. */
	int				game_over;		/**< Флаг окончания игры. */
	int				next_type;		/**< Тип следующей фигуры. */
	int				started;		/**< Флаг старта игры. */
	t_Figure		current_figure;	/**< Текущая фигура. */
	pthread_mutex_t	mutex;			/**< Мьютекс для потоков */
}	t_Game;

/**
 * @brief Очередь действий пользователя.
 */
typedef struct action_queue
{
	t_UserAction	actions[QUEUE_SIZE];	/**< Массив действий. */
	int				head;					/**< Индекс начала очереди. */
	int				tail;					/**< Индекс конца очереди. */
	int				count;					/**< Количество элементов в очереди. */
	pthread_mutex_t	mutex;					/**< Мьютекс для очереди. */
	pthread_cond_t	cond_v;					/**< Условная переменная. */
}	t_ActionQueue;

void			userInput(t_UserAction action, bool hold);
t_GameInfo		updateCurrentState(void);
int				game_over(void);
void			game_init(void);
int				game_started(void);
void			game_destroy(void);

#endif