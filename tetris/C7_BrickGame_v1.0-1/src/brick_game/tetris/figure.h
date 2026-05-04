/**
 * @file figure.h
 * @brief Работа с фигурами Тетрис.
 */
#ifndef FIGURE_H
# define FIGURE_H

# define FIG_X		4	/**< Ширина матрицы фигуры */
# define FIG_Y		4	/**< Высота матрицы фигуры */
# define FIG_COUNT	7	/**< Общее количество фигур */

/**
 * @brief Типы фигур.
 */
typedef enum figure_type
{
	FIGURE_I,	/**< Фигура I (палка) */
	FIGURE_O,	/**< Фигура O (квадрат) */
	FIGURE_T,	/**< Фигура T */
	FIGURE_S,	/**< Фигура S */
	FIGURE_Z,	/**< Фигура Z */
	FIGURE_J,	/**< Фигура J */
	FIGURE_L	/**< Фигура L */
}	t_figure_type;

/**
 * @brief Структура фигуры.
 */
typedef struct figure
{
	int				shape[FIG_Y][FIG_X];	/**< Матрица фигуры */
	t_figure_type	type;					/**< Тип фигуры */
	int				x;						/**< Позиция по горизонтали */
	int				y;						/**< Позиция по вертикали */
}	t_Figure;

void	generate_random_figure(int **dest, int type);

#endif