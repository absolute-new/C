/**
 * @file frontend.h
 * @brief Фронтэнд Тетрис (отрисовка).
 */
#ifndef FRONTEND_H
# define FRONTEND_H

# include <string.h>
# include <ncurses.h>
# include "../../brick_game/tetris/tetris.h"

# define RED     	1	/**< Красный цвет. */
# define PINK    	2	/**< Розовый цвет. */
# define BLUE    	3	/**< Синий цвет. */
# define GREEN   	4	/**< Зелёный цвет. */
# define MAGENTA 	5	/**< Пурпурный цвет. */
# define ORANGE  	6	/**< Оранжевый цвет. */
# define YELLOW  	7	/**< Желтый цвет. */
# define FIELD   	11	/**< Цвет поля. */
# define INFO    	12	/**< Цвет информационной панели. */
# define NO_ACTION	-1	/**< Нет действия пользователя. */

# define PANEL_START 22	/**< Начало панели информации (Х). */
# define PANEL_WIDTH 20	/**< Ширина панели информации. */
# define CENTER(text) (PANEL_START + (PANEL_WIDTH - strlen(text)) / 2) /**< Центрирование текста. */
# define PANEL_RIGHT (PANEL_START + PANEL_WIDTH - 1) /**< Правая граница панели. */

/**
 * @brief Отрисовка блока с указанием цвета.
 */
# define PRINT_BLOCK(color)			\
	do								\
	{								\
		attron(COLOR_PAIR(color));	\
		printw("  ");				\
		attroff(COLOR_PAIR(color));	\
	} while (0);

void			init_frontend(void);
void			cleanup_frontend(void);
void			render_game(t_GameInfo info);
void			draw_game_over(void);

#endif