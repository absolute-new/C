/**
 * @file wall_kick.h
 * @brief Система смещений для вращения фигур.
 */
#ifndef WALL_KICK_H
# define WALL_KICK_H

/**
 * @brief Количество попыток смещения.
 */
# define KICK_COUNT 5

/**
 * @brief Структура одного смещения.
 */
typedef struct kick
{
	int	dx;	/**< Смещение по горизонтали. */
	int	dy;	/**< Смещение по вертикали. */
}	t_wall_kick;

void	get_clockwise_kicks(t_wall_kick kicks[KICK_COUNT]);
void	get_i_figure_kicks(t_wall_kick kicks[KICK_COUNT]);

#endif	