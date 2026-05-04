/**
 * @file wall_kick.c
 * @brief Реализация механики смещения.
 */
#include "wall_kick.h"

/**
 * @brief Переменная для фигур кроме I.
 */
static const t_wall_kick g_clockwise_kicks[KICK_COUNT] = {
    {0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};

/**
 * @brief Переменная для фигуры I.
 */
static const t_wall_kick g_i_figure_kicks[KICK_COUNT] = {
    {0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, 2}};

/**
 * @brief Получение смещений для стандартных фигур.
 * @param kicks Массив смещений.
 */
void get_clockwise_kicks(t_wall_kick kicks[KICK_COUNT]) {
  int i;

  if (!kicks) return;
  i = 0;
  while (i < KICK_COUNT) {
    kicks[i] = g_clockwise_kicks[i];
    i++;
  }
}

/**
 * @brief Получение смещений для фигуры I.
 * @param kicks Массив смещений.
 */
void get_i_figure_kicks(t_wall_kick kicks[KICK_COUNT]) {
  int i;

  if (!kicks) return;
  i = 0;
  while (i < KICK_COUNT) {
    kicks[i] = g_i_figure_kicks[i];
    i++;
  }
}
