#include <check.h>

#include "utils.h"

START_TEST(test_no_collision_center) {
  int **field;
  t_Figure g_fig;

  field = create_empty_field();
  set_simple_figure(&g_fig, 5, 5);
  ck_assert_int_eq(check_collision(field, &g_fig), 0);
  free_field(field);
}
END_TEST

START_TEST(test_collision_left_wall) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, -1, 5);
  ck_assert_int_eq(check_collision(field, &fig), 1);
  free_field(field);
}
END_TEST

START_TEST(test_collision_right_wall) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, WIDTH, 5);
  ck_assert_int_eq(check_collision(field, &fig), 1);
  free_field(field);
}

START_TEST(test_collision_bottom) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 5, HEIGHT);
  ck_assert_int_eq(check_collision(field, &fig), 1);
  free_field(field);
}

START_TEST(test_collision_with_block) {
  t_Figure g_fig;
  int **field;

  field = create_empty_field();
  field[5][5] = 1;
  set_simple_figure(&g_fig, 5, 5);
  ck_assert_int_eq(check_collision(field, &g_fig), 1);
  free_field(field);
}

START_TEST(test_collision_multi_block_figure) {
  int **field = create_empty_field();
  t_Figure fig;

  field[6][6] = 1;
  set_figure_z(&fig, 5, 5);
  ck_assert_int_eq(check_collision(field, &fig), 1);
  free_field(field);
}
END_TEST

Suite *collision_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("Collision");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_no_collision_center);
  tcase_add_test(tc, test_collision_left_wall);
  tcase_add_test(tc, test_collision_right_wall);
  tcase_add_test(tc, test_collision_bottom);
  tcase_add_test(tc, test_collision_with_block);
  tcase_add_test(tc, test_collision_multi_block_figure);
  suite_add_tcase(s, tc);
  return (s);
}
