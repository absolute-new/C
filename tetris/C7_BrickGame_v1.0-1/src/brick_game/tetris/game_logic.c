/**
 * @file game_logic.c
 * @brief Реализация игровой логики Тетрис.
 */
#include "game_logic.h"

#include <stdlib.h>
/* Function prototypes */
static int is_cell_collision(int **field, const t_Figure *figure, int i, int j);
static void rotate_matrix(t_Figure *dst, const t_Figure *src);
static int is_line_full(int **field, int y);
static void shift_lines_down(int **field, int start_y);
static void update_score_and_level(int lines, int *score, int *level,
                                   int *speed);

/**
 * @brief Проверка коллизии блока фигуры с полем.
 * @param field Игровое поле.
 * @param figure Указатель на фигуру.
 * @param i Координата Y в матрице фигуры.
 * @param j Координата X в матрице фигуры.
 * @return 1 если есть коллизия, 0 если нет.
 */
static int is_cell_collision(int **field, const t_Figure *figure, int i,
                             int j) {
  int field_x;
  int field_y;
  int res;

  res = 0;
  field_x = figure->x + j;
  field_y = figure->y + i;
  if (field_x < 0 || field_x >= WIDTH) res = 1;
  if (!res && field_y >= HEIGHT) res = 1;
  if (!res && field_y >= 0 && field[field_y][field_x]) res = 1;
  return (res);
}

/**
 * @brief Поворот матрицы фигуры по часовой стрелке.
 * @param dst Указатель на фигуру для сохранения поворота.
 * @param src Указатель на исходную фигуру.
 */
static void rotate_matrix(t_Figure *dst, const t_Figure *src) {
  int i;
  int j;
  t_Figure copy;

  copy = *src;
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      copy.shape[j][FIG_Y - 1 - i] = src->shape[i][j];
      j++;
    }
    i++;
  }
  *dst = copy;
}

/**
 * @brief Проверка коллизии всей фигуры с полем.
 * @param field Игровое поле.
 * @param figure Указатель на фигуру.
 * @return 1 если есть коллизия, 0 если нет.
 */
int check_collision(int **field, const t_Figure *figure) {
  int i;
  int j;

  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      if (figure->shape[i][j] && is_cell_collision(field, figure, i, j))
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

/**
 * @brief Попытка переместить фигуру.
 * @param field Игровое поле.
 * @param figure Указатель на фигуру.
 * @param dx Смещение по горизонтали.
 * @param dy Смещение по вертикали.
 * @return 1 если удалось перемещение, 0 если нет.
 */
int try_move(int **field, t_Figure *figure, int dx, int dy) {
  t_Figure copy;
  int res;

  res = 0;
  copy = *figure;
  copy.x += dx;
  copy.y += dy;
  if (!check_collision(field, &copy)) {
    figure->x += dx;
    figure->y += dy;
    res = 1;
  }
  return (res);
}

/**
 * @brief Попытка повернуть фигуру.
 * @param field Игровое поле.
 * @param figure Указатель на фигуру.
 */
void try_rotate(int **field, t_Figure *figure) {
  t_Figure copy;
  int kick;
  t_wall_kick kicks[KICK_COUNT];

  if (figure->type == FIGURE_I)
    get_i_figure_kicks(kicks);
  else
    get_clockwise_kicks(kicks);
  kick = 0;
  while (kick < KICK_COUNT) {
    copy = *figure;
    rotate_matrix(&copy, figure);
    copy.x += kicks[kick].dx;
    copy.y += kicks[kick].dy;
    if (!check_collision(field, &copy)) {
      *figure = copy;
      return;
    }
    kick++;
  }
}

/**
 * @brief Прилипание фигуры к полю.
 * @param field Игровое поле.
 * @param figure Указатель на фигуру.
 */
void attach_figure(int **field, const t_Figure *figure) {
  int i;
  int j;
  int field_x;
  int field_y;

  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      if (figure->shape[i][j]) {
        field_x = figure->x + j;
        field_y = figure->y + i;
        if (field_x >= 0 && field_x < WIDTH && field_y >= 0 && field_y < HEIGHT)
          field[field_y][field_x] = figure->type + 1;
      }
      j++;
    }
    i++;
  }
}

/**
 * @brief Проверка, заполнена ли линия полностью.
 * @param field Игровое поле.
 * @param y Координата Y
 * @return 1 если линия заполнена, 0 если нет.
 */
static int is_line_full(int **field, int y) {
  int x;
  int full;

  x = 0;
  full = 1;
  while (x < WIDTH) {
    if (!field[y][x]) full = 0;
    x++;
  }
  return (full);
}

/**
 * @brief Сдвиг линий вниз после удаления.
 * @param field Игровое поле.
 * @param start_y Строка, с которой начинается сдвиг.
 */
static void shift_lines_down(int **field, int start_y) {
  int y;
  int x;

  y = start_y;
  while (y > 0) {
    x = 0;
    while (x < WIDTH) {
      field[y][x] = field[y - 1][x];
      x++;
    }
    y--;
  }
  x = 0;
  while (x < WIDTH) {
    field[0][x] = 0;
    x++;
  }
}

/**
 * @brief Обновление счёта и уровня.
 * @param lines Количество удалённых линий.
 * @param score Указатель на счёт.
 * @param level Указатель на уровень.
 * @param speed Указатель на скорость.
 */
static void update_score_and_level(int lines, int *score, int *level,
                                   int *speed) {
  const int points[] = {0, 100, 300, 700, 1500};
  int add;
  int new_level;

  if (lines <= 4)
    add = points[lines];
  else
    add = points[4];
  *score += add;
  new_level = *score / 600 + 1;
  if (new_level > 10) new_level = 10;
  if (new_level != *level) {
    *level = new_level;
    *speed = 600 / (1 + (*level - 1) * 0.5);
    if (*speed < 50) *speed = 50;
  }
}

/**
 * @brief Удаление заполненных линий и обновление параметров игры.
 * @param field Игровое поле.
 * @param score Указатель на счёт.
 * @param level Указатель на уровень.
 * @param speed Указатель на скорость.
 * @return Количество удалённых линий.
 */
int clear_lines(int **field, int *score, int *level, int *speed) {
  int y;
  int lines;

  lines = 0;
  y = HEIGHT - 1;
  while (y >= 0) {
    if (is_line_full(field, y)) {
      shift_lines_down(field, y);
      lines++;
    } else
      y--;
  }
  if (lines > 0) update_score_and_level(lines, score, level, speed);
  return (lines);
}

/**
 * @brief Создание новой фигуры на поле.
 * @param field Игровое поле.
 * @param next Матрица следующей фигуры.
 * @param current Указатель на текущую фигуру.
 * @param game_over Указатель на флаг окончания игры.
 * @param next_type Указатель на тип следующей фигуры.
 * @return 1 если спавн удался, 0 если нет.
 */
int spawn_figure(int **field, int **next, t_Figure *current, int *game_over,
                 int *next_type) {
  int i;
  int j;

  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      current->shape[i][j] = next[i][j];
      j++;
    }
    i++;
  }
  current->type = *next_type;
  current->x = WIDTH / 2 - 2;
  current->y = 0;
  *next_type = rand() % 7;
  generate_random_figure(next, *next_type);
  if (check_collision(field, current)) {
    *game_over = 1;
    return (0);
  }
  return (1);
}
