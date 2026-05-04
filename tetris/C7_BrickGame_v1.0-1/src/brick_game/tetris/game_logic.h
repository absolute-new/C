/**
 * @file game_logic.h
 * @brief Игровая логика игры Тетрис.
 */
#ifndef GAME_LOGIC_H
# define GAME_LOGIC_H

# include "figure.h"
# include "wall_kick.h"

# define WIDTH		10	/**< Ширина поля  */
# define HEIGHT		20	/**< Высота поля  */

int		check_collision(int **field, const t_Figure *figure);
int		try_move(int **field, t_Figure *figure, int dx, int dy);
void	try_rotate(int **field, t_Figure *figure);
void	attach_figure(int **field, const t_Figure *figure);
int		clear_lines(int **field, int *score, int *level, int *speed);
int		spawn_figure(int **field, int **next, t_Figure *figure,
			int *game_over, int *next_type);

#endif