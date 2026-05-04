#ifndef UTILS_H
# define UTILS_H

# include "../brick_game/tetris/game_logic.h"
# include "../brick_game/tetris/memory.h"

extern const int	g_shapes[7][FIG_Y][FIG_X];

int		**create_empty_field(void);
void	free_field(int **field);
void	set_simple_figure(t_Figure *figure, int x, int y);
void	set_figure(t_Figure *figure, const int shape[FIG_Y][FIG_X],
			int type, int x, int y);
int		compare_figures(t_Figure *a, t_Figure *b);
void	set_figure_i(t_Figure *figure, int x, int y);
void	set_figure_o(t_Figure *figure, int x, int y);
void	set_figure_t(t_Figure *figure, int x, int y);
void	set_figure_s(t_Figure *figure, int x, int y);
void	set_figure_z(t_Figure *figure, int x, int y);
void	set_figure_j(t_Figure *figure, int x, int y);
void	set_figure_l(t_Figure *figure, int x, int y);
void	fill_line(int **field, int y, int value);
void	copy_figure_to_matrix(int **dest, const t_Figure *src);

#endif