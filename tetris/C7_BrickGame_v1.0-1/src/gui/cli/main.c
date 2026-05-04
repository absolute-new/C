/**
 * @file main.c
 * @brief Точка входа в программу Тетрис.
 */
#include <unistd.h>

#include "../../brick_game/tetris/tetris.h"
#include "input.h"
#include "threads.h"

/**
 * @brief Главная функция программы .
 *
 * Инициализирует фронтэнд, игровую логику, очередь действий и потоки.
 * Обрабатывает в цикле ввод пользователя
 * После завершения останавливает потоки и освобождает ресурсы.
 *
 * @return 0 при успехе.
 */
int main(void) {
  t_UserAction action;

  init_frontend();
  game_init();
  init_queue();
  start_game_threads();
  while (true) {
    action = get_user_action();
    if (action == Terminate) break;
    if (action != (t_UserAction)NO_ACTION) push_action(action);
    usleep(20000);
  }
  stop_game_threads();
  wait_game_threads();
  cleanup_frontend();
  return (0);
}
