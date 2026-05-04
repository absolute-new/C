#include <check.h>

#include "../brick_game/tetris/tetris.h"
#include "utils.h"

void teardown(void) { game_destroy(); }

START_TEST(test_game_init) {
  t_GameInfo info;

  game_init();
  info = updateCurrentState();
  ck_assert_int_eq(info.score, 0);
  ck_assert_int_eq(info.level, 1);
  ck_assert_int_eq(info.speed, 600);
  ck_assert_int_eq(info.pause, 0);
  ck_assert_int_eq(game_over(), 0);
  ck_assert_int_eq(game_started(), 0);
  free_matrix(info.field, HEIGHT);
  free_matrix(info.next, FIG_Y);
}
END_TEST

START_TEST(test_game_started) {
  game_init();
  ck_assert_int_eq(game_started(), 0);
  userInput(Start, false);
  ck_assert_int_eq(game_started(), 1);
}
END_TEST

START_TEST(test_game_over_flag) {
  game_init();
  userInput(Start, false);
  ck_assert_int_eq(game_over(), 0);
  userInput(Action, false);
  userInput(Terminate, false);
  ck_assert_int_eq(game_over(), 1);
}
END_TEST

START_TEST(test_user_input) {
  t_GameInfo info;

  game_init();
  userInput(Start, false);
  info = updateCurrentState();
  ck_assert_int_eq(info.score, 0);
  free_matrix(info.field, HEIGHT);
  free_matrix(info.next, FIG_Y);
}
END_TEST

START_TEST(test_updateCurrentState) {
  t_GameInfo info;

  game_init();
  userInput(Start, false);
  info = updateCurrentState();
  ck_assert_ptr_nonnull(info.field);
  ck_assert_ptr_nonnull(info.next);
  ck_assert_int_eq(info.score, 0);
  ck_assert_int_eq(info.level, 1);
  free_matrix(info.field, HEIGHT);
  free_matrix(info.next, FIG_Y);
}
END_TEST

START_TEST(test_updateCurrentState_with_figure) {
  t_GameInfo info;
  int has_block;
  int i;
  int j;

  game_init();
  userInput(Start, false);
  userInput(Down, false);
  info = updateCurrentState();
  has_block = 0;
  i = 0;
  while (i < HEIGHT && !has_block) {
    j = 0;
    while (j < WIDTH && !has_block) {
      if (info.field[i][j] > 0) has_block = 1;
      j++;
    }
    i++;
  }
  ck_assert_int_eq(has_block, 1);
  free_matrix(info.field, HEIGHT);
  free_matrix(info.next, FIG_Y);
}
END_TEST

Suite *tetris_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("Tetris");
  tc = tcase_create("Core");
  tcase_add_checked_fixture(tc, NULL, teardown);
  tcase_add_test(tc, test_game_init);
  tcase_add_test(tc, test_game_started);
  tcase_add_test(tc, test_game_over_flag);
  tcase_add_test(tc, test_user_input);
  tcase_add_test(tc, test_updateCurrentState);
  tcase_add_test(tc, test_updateCurrentState_with_figure);
  suite_add_tcase(s, tc);
  return (s);
}