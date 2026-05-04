#include <check.h>

#include "utils.h"

START_TEST(test_spawn_figure_no_collision) {
  int **field;
  int **next;
  t_Figure current;
  t_Figure temp;
  int game_over;
  int next_type;
  int result;

  field = create_empty_field();
  next = allocate_matrix(FIG_Y, FIG_X);
  game_over = 0;
  next_type = FIGURE_I;
  set_figure_i(&temp, 0, 0);
  copy_figure_to_matrix(next, &temp);
  result = spawn_figure(field, next, &current, &game_over, &next_type);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(game_over, 0);
  ck_assert_int_eq(current.x, WIDTH / 2 - 2);
  ck_assert_int_eq(current.y, 0);
  free_field(field);
  free_matrix(next, FIG_Y);
}
END_TEST

START_TEST(test_spawn_figure_game_over) {
  int **field;
  int **next;
  t_Figure current;
  t_Figure temp;
  int game_over;
  int next_type;
  int result;

  field = create_empty_field();
  next = allocate_matrix(FIG_Y, FIG_X);
  game_over = 0;
  next_type = FIGURE_O;
  fill_line(field, 0, 1);
  fill_line(field, 1, 1);
  set_figure_o(&temp, 0, 0);
  copy_figure_to_matrix(next, &temp);
  result = spawn_figure(field, next, &current, &game_over, &next_type);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(game_over, 1);
  free_field(field);
  free_matrix(next, FIG_Y);
}
END_TEST

Suite *spawn_figure_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("spawn_figure");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_spawn_figure_no_collision);
  tcase_add_test(tc, test_spawn_figure_game_over);
  suite_add_tcase(s, tc);
  return (s);
}