#include "utils.h"

#include <stdlib.h>

int **create_empty_field(void) {
  int **field;
  int i;

  field = malloc(HEIGHT * sizeof(int *));
  i = 0;
  while (i < HEIGHT) {
    field[i] = calloc(WIDTH, sizeof(int));
    i++;
  }
  return (field);
}

void free_field(int **field) {
  int i;

  i = 0;
  while (i < HEIGHT) {
    free(field[i]);
    i++;
  }
  free(field);
}

void set_simple_figure(t_Figure *figure, int x, int y) {
  int i;
  int j;

  figure->x = x;
  figure->y = y;
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      figure->shape[i][j] = 0;
      j++;
    }
    i++;
  }
  figure->shape[0][0] = 1;
}

void set_figure(t_Figure *figure, const int shape[FIG_Y][FIG_X], int type,
                int x, int y) {
  int i;
  int j;

  figure->x = x;
  figure->y = y;
  figure->type = type;
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      figure->shape[i][j] = shape[i][j];
      j++;
    }
    i++;
  }
}

int compare_figures(t_Figure *a, t_Figure *b) {
  int i;
  int j;

  if (a->x != b->x || a->y != b->y || a->type != b->type) return (0);
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      if (a->shape[i][j] != b->shape[i][j]) return (0);
      j++;
    }
    i++;
  }
  return (1);
}

void set_figure_i(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_I], FIGURE_I, x, y);
}

void set_figure_t(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_T], FIGURE_T, x, y);
}

void set_figure_s(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_S], FIGURE_S, x, y);
}

void set_figure_z(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_Z], FIGURE_Z, x, y);
}

void set_figure_j(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_J], FIGURE_J, x, y);
}

void set_figure_l(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_L], FIGURE_L, x, y);
}

void set_figure_o(t_Figure *figure, int x, int y) {
  set_figure(figure, g_shapes[FIGURE_O], FIGURE_O, x, y);
}

void fill_line(int **field, int y, int value) {
  int x;

  x = 0;
  while (x < WIDTH) {
    field[y][x] = value;
    x++;
  }
}

void copy_figure_to_matrix(int **dest, const t_Figure *src) {
  int i;
  int j;

  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      dest[i][j] = src->shape[i][j];
      j++;
    }
    i++;
  }
}
