/**
 * @file memory.c
 * @brief Реализация работы с памятью.
 */
#include "memory.h"

#include <stdlib.h>

/**
 * @brief Выделение динамической памяти под матрицы.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на выделенную матрицу или NULL при ошибке.
 */
int **allocate_matrix(int rows, int cols) {
  int **matrix;
  int i;

  matrix = (int **)malloc(rows * sizeof(int *));
  if (!matrix) return (NULL);
  i = 0;
  while (i < rows) {
    matrix[i] = (int *)calloc(cols, sizeof(int));
    if (!matrix[i]) {
      while (--i >= 0) free(matrix[i]);
      free(matrix);
      return (NULL);
    }
    i++;
  }
  return (matrix);
}

/**
 * @brief Освобождение динамической памяти матрицы.
 * @param matrix Указатель на матрицу.
 * @param rows Количество строк.
 */
void free_matrix(int **matrix, int rows) {
  int i;

  if (!matrix) return;
  i = 0;
  while (i < rows) {
    free(matrix[i]);
    i++;
  }
  free(matrix);
}

/**
 * @brief Копирование матрицы.
 * @param src Исходная матрица.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на копию матрицы или NULL при ошибке.
 */
int **copy_matrix(int **src, int rows, int cols) {
  int **dst;
  int i;
  int j;

  dst = allocate_matrix(rows, cols);
  if (!dst) return (NULL);
  i = 0;
  while (i < rows) {
    j = 0;
    while (j < cols) {
      dst[i][j] = src[i][j];
      j++;
    }
    i++;
  }
  return (dst);
}
