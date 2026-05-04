/**
 * @file input.c
 * @brief Реализация очереди действий пользователя.
 */
#include "input.h"

#include <time.h>

/**
 * @brief Очередь для хранения действий.
 */
static t_ActionQueue g_queue = {.head = 0, .tail = 0, .count = 0};

/**
 * @brief Инициализация мьютекса и условной переменной.
 */
void init_queue(void) {
  pthread_mutex_init(&g_queue.mutex, NULL);
  pthread_cond_init(&g_queue.cond_v, NULL);
}

/**
 * @brief Добавление действия в очередь.
 * @param action Действие пользователя.
 */
void push_action(t_UserAction action) {
  pthread_mutex_lock(&g_queue.mutex);
  if (g_queue.count < QUEUE_SIZE) {
    g_queue.actions[g_queue.tail] = action;
    g_queue.tail = (g_queue.tail + 1) % QUEUE_SIZE;
    g_queue.count++;
    pthread_cond_signal(&g_queue.cond_v);
  }
  pthread_mutex_unlock(&g_queue.mutex);
}

/**
 * @brief Извлечение действия из очереди.
 * @return Действие пользователя или NO_ACTION при таймауте.
 */
t_UserAction pop_action(void) {
  t_UserAction action;
  struct timespec ts;

  action = NO_ACTION;
  pthread_mutex_lock(&g_queue.mutex);
  if (g_queue.count == 0) {
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_nsec += 1 * 1000000;
    if (ts.tv_nsec >= 1000000000) {
      ts.tv_sec++;
      ts.tv_nsec -= 1000000000;
    }
    pthread_cond_timedwait(&g_queue.cond_v, &g_queue.mutex, &ts);
  }
  if (g_queue.count > 0) {
    action = g_queue.actions[g_queue.head];
    g_queue.head = (g_queue.head + 1) % QUEUE_SIZE;
    g_queue.count--;
  }
  pthread_mutex_unlock(&g_queue.mutex);
  return (action);
}

/**
 * @brief Чтение действия пользователя из потока stdin.
 * @return Действие пользователя или NO_ACTION, если клавиша не нажата.
 */
t_UserAction get_user_action(void) {
  int ch;

  ch = getch();
  if (ch == ERR) return (NO_ACTION);
  switch (ch) {
    case 'q':
    case 'Q':
      return (Terminate);
    case '\n':
      return (Start);
    case 'p':
    case 'P':
      return (Pause);
    case KEY_LEFT:
      return (Left);
    case KEY_RIGHT:
      return (Right);
    case KEY_DOWN:
      return (Down);
    case KEY_UP:
      return (Action);
    case ' ':
      return (Up);
    default:
      return (NO_ACTION);
  }
}
