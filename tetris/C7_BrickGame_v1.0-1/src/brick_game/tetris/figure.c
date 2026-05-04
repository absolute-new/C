/**
 * @file figure.c
 * @brief Реализация функций работы с фигурами.
 */
#include "figure.h"

#include <stdlib.h>
#include <time.h>

/**
 * @brief Массив для мешка фигур.
 */
static const int g_bag[] = {0, 1, 2, 3, 4, 5, 6};

/**
 * @brief Индекс для мешка фигур.
 */
static int g_bag_index = 0;

/**
 * @brief Массив для отсортированных фигур.
 */
static int g_bag_shuffled[FIG_COUNT];

/**
 * @brief Массив форм для всех фигур.
 */
const int g_shapes[FIG_COUNT][FIG_Y][FIG_X] = {
    /* I */
    {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    /* O */
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
    /* T */
    {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
    /* S */
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
    /* Z */
    {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
    /* J */
    {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
    /* L */
    {{0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}}};

/* Function prototypes */
static void shuffle_array(int *array, int size);
static void shuffle_bag(void);
static void copy_figure(int **dest, int idx);

/**
 * @brief Перемешивание фигур (алгоритм Фишера-Йетса).
 * @param array Указатель на массив
 * @param size Размер массива
 */
static void shuffle_array(int *array, int size) {
  int i;
  int j;
  int temp;

  i = size - 1;
  while (i > 0) {
    j = rand() % (i + 1);
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i--;
  }
}

/**
 * @brief Перемешивание мешка фигур.
 */
static void shuffle_bag(void) {
  int i;
  static int initialized = 0;

  if (!initialized) {
    srand(time(NULL));
    initialized = 1;
  }
  i = 0;
  while (i < FIG_COUNT) {
    g_bag_shuffled[i] = g_bag[i];
    i++;
  }
  shuffle_array(g_bag_shuffled, FIG_COUNT);
}

/**
 * @brief Копирование формы фигуры в матрицу.
 * @param dest Матрица назначения.
 * @param idx Индекс фигуры в массиве g_shapes.
 */
static void copy_figure(int **dest, int idx) {
  int i;
  int j;

  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      dest[i][j] = g_shapes[idx][i][j];
      j++;
    }
    i++;
  }
}

/**
 * @brief Генерация случайной фигуры.
 * @param dest Матрица для записи формы.
 * @param type Тип фигуры (0-6) или -1 для случайного из мешка.
 */
void generate_random_figure(int **dest, int type) {
  static int need_shuffle = 1;

  if (type == -1) {
    if (need_shuffle) {
      shuffle_bag();
      g_bag_index = 0;
      need_shuffle = 0;
    }
    type = g_bag_shuffled[g_bag_index++];
    if (g_bag_index >= FIG_COUNT) need_shuffle = 1;
  }
  copy_figure(dest, type);
}
