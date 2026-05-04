#include <check.h>

#include "utils.h"

START_TEST(test_clear_one_line) {
  int **field;
  int score;
  int level;
  int speed;
  int lines;

  field = create_empty_field();
  score = 0;
  level = 1;
  speed = 500;
  fill_line(field, 15, 1);
  lines = clear_lines(field, &score, &level, &speed);
  ck_assert_int_eq(lines, 1);
  ck_assert_int_eq(score, 100);
  ck_assert_int_eq(field[15][0], 0);
  free_field(field);
}
END_TEST

START_TEST(test_clear_two_line) {
  int **field;
  int score;
  int level;
  int speed;
  int lines;

  field = create_empty_field();
  score = 0;
  level = 1;
  speed = 500;
  fill_line(field, 10, 1);
  fill_line(field, 11, 1);
  lines = clear_lines(field, &score, &level, &speed);
  ck_assert_int_eq(lines, 2);
  ck_assert_int_eq(score, 300);
  ck_assert_int_eq(field[10][2], 0);
  ck_assert_int_eq(field[11][4], 0);
  free_field(field);
}
END_TEST

START_TEST(test_clear_four_line) {
  int **field;
  int score;
  int level;
  int speed;
  int lines;

  field = create_empty_field();
  score = 0;
  level = 1;
  speed = 500;
  for (int y = 10; y < 14; ++y) fill_line(field, y, 1);
  lines = clear_lines(field, &score, &level, &speed);
  ck_assert_int_eq(lines, 4);
  ck_assert_int_eq(score, 1500);
  for (int y = 10; y < 14; ++y) ck_assert_int_eq(field[y][0], 0);
  free_field(field);
}
END_TEST

START_TEST(test_clear_no_complete_lines) {
  int **field;
  int score;
  int level;
  int speed;
  int lines;

  field = create_empty_field();
  score = 0;
  level = 1;
  speed = 500;
  for (int x = 0; x < 5; ++x) field[10][x] = 1;
  lines = clear_lines(field, &score, &level, &speed);
  ck_assert_int_eq(lines, 0);
  ck_assert_int_eq(score, 0);
  for (int x = 0; x < 5; ++x) ck_assert_int_eq(field[10][x], 1);
  free_field(field);
}
END_TEST

START_TEST(test_level_up) {
  int **field;
  int score;
  int level;
  int speed;
  int lines;

  field = create_empty_field();
  score = 0;
  level = 1;
  speed = 500;
  lines = 0;
  for (int i = 0; i < 6; i++) {
    fill_line(field, i, 1);
    lines += clear_lines(field, &score, &level, &speed);
  }
  ck_assert_int_eq(lines, 6);
  ck_assert_int_eq(score, 600);
  ck_assert_int_eq(level, 2);
  free_field(field);
}
END_TEST

Suite *clear_lines_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("clear_lines");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_clear_one_line);
  tcase_add_test(tc, test_clear_two_line);
  tcase_add_test(tc, test_clear_four_line);
  tcase_add_test(tc, test_clear_no_complete_lines);
  tcase_add_test(tc, test_level_up);
  suite_add_tcase(s, tc);
  return (s);
}