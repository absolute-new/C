#include <check.h>

#include "utils.h"

START_TEST(test_rotate_t_shape) {
  int **field;
  t_Figure fig;
  t_Figure expect;

  int expected_shape[4][4] = {
      {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  field = create_empty_field();
  set_figure_t(&fig, 5, 5);
  set_figure(&expect, expected_shape, FIGURE_T, 5, 5);
  try_rotate(field, &fig);
  ck_assert_int_eq(compare_figures(&fig, &expect), 1);
  free_field(field);
}
END_TEST

START_TEST(test_rotate_i_figure) {
  int **field;
  t_Figure fig;
  t_Figure expected;

  int expected_shape[4][4] = {
      {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  field = create_empty_field();
  set_figure_i(&fig, 5, 5);
  set_figure(&expected, expected_shape, FIGURE_I, 5, 5);
  try_rotate(field, &fig);
  ck_assert_int_eq(compare_figures(&fig, &expected), 1);
  free_field(field);
}
END_TEST

START_TEST(test_rotate_i_horizontal_to_vertical) {
  int **field;
  t_Figure fig;
  t_Figure expected;

  int vertical_shape[4][4] = {
      {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  field = create_empty_field();
  set_figure_i(&fig, 3, 5);
  set_figure(&expected, vertical_shape, FIGURE_I, 3, 5);
  try_rotate(field, &fig);
  ck_assert_int_eq(compare_figures(&fig, &expected), 1);
  free_field(field);
}
END_TEST

START_TEST(test_rotate_i_vertical_to_horizontal_near_left_wall) {
  int **field;
  t_Figure fig;
  t_Figure expected;

  int vertical_shape[4][4] = {
      {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  int expected_shape[4][4] = {
      {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  field = create_empty_field();
  set_figure(&fig, vertical_shape, FIGURE_I, 0, 5);
  set_figure(&expected, expected_shape, FIGURE_I, 0, 5);
  try_rotate(field, &fig);
  for (int i = 0; i < FIG_Y; i++)
    for (int j = 0; j < FIG_X; j++)
      ck_assert_int_eq(fig.shape[i][j], expected.shape[i][j]);
  free_field(field);
}
END_TEST

Suite *try_rotate_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("try_rotate");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_rotate_t_shape);
  tcase_add_test(tc, test_rotate_i_figure);
  tcase_add_test(tc, test_rotate_i_horizontal_to_vertical);
  tcase_add_test(tc, test_rotate_i_vertical_to_horizontal_near_left_wall);
  suite_add_tcase(s, tc);
  return (s);
}
