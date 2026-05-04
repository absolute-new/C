#include <check.h>

#include "utils.h"

START_TEST(test_clockwise_kicks) {
  t_wall_kick kicks[KICK_COUNT];

  get_clockwise_kicks(kicks);

  ck_assert_int_eq(kicks[0].dx, 0);
  ck_assert_int_eq(kicks[0].dy, 0);
  ck_assert_int_eq(kicks[1].dx, -1);
  ck_assert_int_eq(kicks[1].dy, 0);
  ck_assert_int_eq(kicks[2].dx, -1);
  ck_assert_int_eq(kicks[2].dy, 1);
  ck_assert_int_eq(kicks[3].dx, 0);
  ck_assert_int_eq(kicks[3].dy, -2);
  ck_assert_int_eq(kicks[4].dx, -1);
  ck_assert_int_eq(kicks[4].dy, -2);
}
END_TEST

START_TEST(test_i_figure_kicks) {
  t_wall_kick kicks[KICK_COUNT];

  get_i_figure_kicks(kicks);

  ck_assert_int_eq(kicks[0].dx, 0);
  ck_assert_int_eq(kicks[0].dy, 0);
  ck_assert_int_eq(kicks[1].dx, -2);
  ck_assert_int_eq(kicks[1].dy, 0);
  ck_assert_int_eq(kicks[2].dx, 1);
  ck_assert_int_eq(kicks[2].dy, 0);
  ck_assert_int_eq(kicks[3].dx, -2);
  ck_assert_int_eq(kicks[3].dy, 1);
  ck_assert_int_eq(kicks[4].dx, 1);
  ck_assert_int_eq(kicks[4].dy, 2);
}
END_TEST

START_TEST(test_clockwise_kicks_null) { get_clockwise_kicks(NULL); }
END_TEST

START_TEST(test_i_figure_kicks_null) { get_i_figure_kicks(NULL); }
END_TEST

Suite *wall_kick_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("wall_kick");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_clockwise_kicks);
  tcase_add_test(tc, test_i_figure_kicks);
  tcase_add_test(tc, test_clockwise_kicks_null);
  tcase_add_test(tc, test_i_figure_kicks_null);
  suite_add_tcase(s, tc);
  return (s);
}
