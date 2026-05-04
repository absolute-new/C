/**
 * @file memory.h
 * @brief Работа с памятью.
 */
#ifndef MEMORY_H
# define MEMORY_H

int		**allocate_matrix(int rows, int cols);
int		**copy_matrix(int **field, int rows, int cols);
void	free_matrix(int **matrix, int rows);

#endif