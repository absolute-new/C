#include <check.h>

Suite *collision_suite(void);
Suite *try_move_suite(void);
Suite *try_rotate_suite(void);
Suite *attach_figure_suite(void);
Suite *clear_lines_suite(void);
Suite *spawn_figure_suite(void);
Suite *wall_kick_suite(void);
Suite *figure_suite(void);
Suite *fsm_suite(void);
Suite *tetris_suite(void);

int main(void) {
  SRunner *sr;
  int failed;
  int i;

  failed = 0;
  Suite *(*s[])(void) = {collision_suite,   try_move_suite,
                         try_rotate_suite,  attach_figure_suite,
                         clear_lines_suite, spawn_figure_suite,
                         wall_kick_suite,   figure_suite,
                         fsm_suite,         tetris_suite};
  i = 0;
  while (i < 10) {
    sr = srunner_create(s[i]());
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    i++;
  }
  return (failed);
}
