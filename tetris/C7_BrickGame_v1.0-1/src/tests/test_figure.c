#include <check.h>

#include "utils.h"

START_TEST(test_generate_random_figure_with_type) {
  int **dest;

  dest = allocate_matrix(FIG_Y, FIG_X);
  generate_random_figure(dest, FIGURE_I);
  ck_assert_int_eq(dest[1][0], 1);
  ck_assert_int_eq(dest[1][1], 1);
  ck_assert_int_eq(dest[1][2], 1);
  ck_assert_int_eq(dest[1][3], 1);

  generate_random_figure(dest, FIGURE_O);
  ck_assert_int_eq(dest[1][1], 1);
  ck_assert_int_eq(dest[1][2], 1);
  ck_assert_int_eq(dest[2][1], 1);
  ck_assert_int_eq(dest[2][2], 1);

  generate_random_figure(dest, FIGURE_T);
  ck_assert_int_eq(dest[1][1], 1);
  ck_assert_int_eq(dest[2][0], 1);
  ck_assert_int_eq(dest[2][1], 1);
  ck_assert_int_eq(dest[2][2], 1);
  free_matrix(dest, FIG_Y);
}
END_TEST

START_TEST(test_generate_random_figure_bag_randomizer) {
  int **dest;
  int i;
  int x;
  int y;
  int has_block;

  dest = allocate_matrix(FIG_Y, FIG_X);
  i = 0;
  while (i < FIG_COUNT) {
    generate_random_figure(dest, -1);
    has_block = 0;
    y = 0;
    while (y < FIG_Y && !has_block) {
      x = 0;
      while (x < FIG_X && !has_block) {
        if (dest[y][x]) has_block = 1;
        x++;
      }
      y++;
    }
    ck_assert_int_eq(has_block, 1);
    i++;
  }
  free_matrix(dest, FIG_Y);
}
END_TEST

START_TEST(test_generate_random_figure_all_types) {
  int **dest;
  int i;
  int j;
  int type;
  int has_block;

  dest = allocate_matrix(FIG_Y, FIG_X);
  type = FIGURE_I;
  while (type <= FIGURE_L) {
    generate_random_figure(dest, type);
    has_block = 0;
    i = 0;
    while (i < FIG_Y && !has_block) {
      j = 0;
      while (j < FIG_X && !has_block) {
        if (dest[i][j]) has_block = 1;
        j++;
      }
      i++;
    }
    ck_assert_int_eq(has_block, 1);
    type++;
  }
  free_matrix(dest, FIG_Y);
}
END_TEST

Suite *figure_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("figure");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_generate_random_figure_with_type);
  tcase_add_test(tc, test_generate_random_figure_bag_randomizer);
  tcase_add_test(tc, test_generate_random_figure_all_types);
  suite_add_tcase(s, tc);
  return (s);
}