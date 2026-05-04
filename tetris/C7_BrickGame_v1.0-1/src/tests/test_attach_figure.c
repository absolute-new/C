#include <check.h>

#include "utils.h"

START_TEST(test_attach_simple) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_figure_i(&fig, 5, 5);
  attach_figure(field, &fig);
  ck_assert_int_eq(field[6][5], FIGURE_I + 1);
  ck_assert_int_eq(field[6][6], FIGURE_I + 1);
  ck_assert_int_eq(field[6][7], FIGURE_I + 1);
  ck_assert_int_eq(field[6][8], FIGURE_I + 1);
  ck_assert_int_eq(field[5][5], 0);
  ck_assert_int_eq(field[5][6], 0);
  free_field(field);
}
END_TEST

START_TEST(test_attach_multi_blocks) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_figure_z(&fig, 5, 5);
  attach_figure(field, &fig);
  ck_assert_int_eq(field[6][5], FIGURE_Z + 1);
  ck_assert_int_eq(field[6][6], FIGURE_Z + 1);
  ck_assert_int_eq(field[5][5], 0);
  ck_assert_int_eq(field[5][6], 0);
  free_field(field);
}
END_TEST

START_TEST(test_attach_inside_borders) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_figure_l(&fig, 0, 0);
  attach_figure(field, &fig);
  ck_assert_int_eq(field[2][0] > 0, 1);
  free_field(field);
}
END_TEST

START_TEST(test_attach_does_not_overflow) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, -1, -1);
  attach_figure(field, &fig);
  ck_assert_int_eq(field[0][0], 0);
  free_field(field);
}
END_TEST

START_TEST(test_attach_partial_overflow) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_figure_i(&fig, -1, 5);
  attach_figure(field, &fig);
  ck_assert_int_eq(field[6][0], FIGURE_I + 1);
  ck_assert_int_eq(field[6][1], FIGURE_I + 1);
  ck_assert_int_eq(field[6][2], FIGURE_I + 1);
  free_field(field);
}
END_TEST

Suite *attach_figure_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("attach_figure");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_attach_simple);
  tcase_add_test(tc, test_attach_multi_blocks);
  tcase_add_test(tc, test_attach_inside_borders);
  tcase_add_test(tc, test_attach_does_not_overflow);
  tcase_add_test(tc, test_attach_partial_overflow);
  suite_add_tcase(s, tc);
  return (s);
}