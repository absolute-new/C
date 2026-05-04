#include <check.h>

#include "utils.h"

START_TEST(test_move_left) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 5, 5);
  ck_assert_int_eq(try_move(field, &fig, -1, 0), 1);
  ck_assert_int_eq(fig.x, 4);
  ck_assert_int_eq(fig.y, 5);
  free_field(field);
}
END_TEST

START_TEST(test_move_right) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 3, 3);
  ck_assert_int_eq(try_move(field, &fig, 1, 0), 1);
  ck_assert_int_eq(fig.x, 4);
  ck_assert_int_eq(fig.y, 3);
  free_field(field);
}
END_TEST

START_TEST(test_move_down) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 5, 5);
  ck_assert_int_eq(try_move(field, &fig, 0, 1), 1);
  ck_assert_int_eq(fig.x, 5);
  ck_assert_int_eq(fig.y, 6);
  free_field(field);
}
END_TEST

START_TEST(test_move_into_left_wall) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 0, 5);
  ck_assert_int_eq(try_move(field, &fig, -1, 0), 0);
  ck_assert_int_eq(fig.x, 0);
  ck_assert_int_eq(fig.y, 5);
  free_field(field);
}
END_TEST

START_TEST(test_move_into_right_wall) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, WIDTH - 1, 5);
  ck_assert_int_eq(try_move(field, &fig, 1, 0), 0);
  ck_assert_int_eq(fig.x, WIDTH - 1);
  ck_assert_int_eq(fig.y, 5);
  free_field(field);
}
END_TEST

START_TEST(test_move_into_block) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  field[5][5] = 1;
  set_simple_figure(&fig, 4, 5);
  ck_assert_int_eq(try_move(field, &fig, 1, 0), 0);
  ck_assert_int_eq(fig.x, 4);
  ck_assert_int_eq(fig.y, 5);
  free_field(field);
}
END_TEST

START_TEST(test_move_down_into_block) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  field[6][5] = 1;
  set_simple_figure(&fig, 5, 5);
  ck_assert_int_eq(try_move(field, &fig, 0, 1), 0);
  ck_assert_int_eq(fig.x, 5);
  ck_assert_int_eq(fig.y, 5);
  free_field(field);
}
END_TEST

START_TEST(test_move_down_to_floor) {
  int **field;
  t_Figure fig;

  field = create_empty_field();
  set_simple_figure(&fig, 5, HEIGHT - 1);
  ck_assert_int_eq(try_move(field, &fig, 0, 1), 0);
  ck_assert_int_eq(fig.x, 5);
  ck_assert_int_eq(fig.y, HEIGHT - 1);
  free_field(field);
}
END_TEST

Suite *try_move_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("try_move");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_move_left);
  tcase_add_test(tc, test_move_right);
  tcase_add_test(tc, test_move_down);
  tcase_add_test(tc, test_move_into_left_wall);
  tcase_add_test(tc, test_move_into_right_wall);
  tcase_add_test(tc, test_move_into_block);
  tcase_add_test(tc, test_move_down_into_block);
  tcase_add_test(tc, test_move_down_to_floor);
  suite_add_tcase(s, tc);
  return (s);
}