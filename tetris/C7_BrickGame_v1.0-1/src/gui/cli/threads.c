/**
 * @file threads.c
 * @brief Реализация многопоточности Тетрис.
 */
#include "threads.h"

#include <pthread.h>
#include <stdatomic.h>
#include <sys/time.h>
#include <unistd.h>

#include "frontend.h"

/**
 * @brief Атомарная переменная старта игры.
 */
static atomic_int g_running = 1;

/**
 * @brief Атомарная переменная Готовности игры.
 */
static atomic_int g_game_ready = 0;

/**
 * @brief Переменная таймера.
 */
static long g_last_tick;

/**
 * @brief Барьер для старта потоков.
 */
static pthread_barrier_t g_barrier;

/**
 * @brief Поток для игровой логики.
 */
static pthread_t g_tid_game;

/**
 * @brief Поток для отрисовки.
 */
static pthread_t g_tid_render;

/**
 * @brief Получение текущего времени в мс.
 * @return Текущее время в мс.
 */
long get_current_ms(void) {
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief Поток игровой логики.
 * @param arg Не используется.
 */
void *game_thread(void *arg) {
  t_GameInfo info;
  t_UserAction action;
  long now;

  (void)arg;
  pthread_barrier_wait(&g_barrier);
  g_last_tick = get_current_ms();
  while (atomic_load(&g_running)) {
    action = pop_action();
    if (action == Terminate) {
      atomic_store(&g_running, 0);
      break;
    }
    if (action != (t_UserAction)NO_ACTION) userInput(action, false);
    now = get_current_ms();
    if (!game_over()) {
      info = updateCurrentState();
      if (now - g_last_tick >= info.speed && !info.pause) {
        userInput(Down, false);
        g_last_tick = now;
      }
      free_matrix(info.field, HEIGHT);
      free_matrix(info.next, FIG_Y);
    }
  }
  return (NULL);
}

/**
 * @brief Поток Отрисовки.
 * @param arg Не используется.
 */
void *render_thread(void *arg) {
  t_GameInfo info;

  (void)arg;
  pthread_barrier_wait(&g_barrier);
  while (!atomic_load(&g_game_ready)) usleep(10000);
  while (atomic_load(&g_running)) {
    if (game_over()) {
      draw_game_over();
    } else {
      info = updateCurrentState();
      if (info.field && info.next) {
        render_game(info);
      }
      free_matrix(info.field, HEIGHT);
      free_matrix(info.next, FIG_Y);
    }
    usleep(6000);
  }
  return (NULL);
}

/**
 * @brief Запуск игровых потоков.
 */
void start_game_threads(void) {
  atomic_store(&g_game_ready, 1);
  pthread_barrier_init(&g_barrier, NULL, THREAD_COUNT);
  pthread_create(&g_tid_game, NULL, game_thread, NULL);
  pthread_create(&g_tid_render, NULL, render_thread, NULL);
  pthread_barrier_wait(&g_barrier);
}

/**
 * @brief Остановка игровых потоков.
 */
void stop_game_threads(void) { atomic_store(&g_running, 0); }

/**
 * @brief Ожидание завершения игровых потоков.
 */
void wait_game_threads(void) {
  pthread_join(g_tid_game, NULL);
  pthread_join(g_tid_render, NULL);
}
