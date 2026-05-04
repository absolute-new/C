/**
 * @file tetris.c
 * @brief Реализация игры Тетрис.
 */
#include "tetris.h"

#include <stdio.h>
#include <stdlib.h>

#include "fsm.h"

/**
 * @brief Переменная для состояния игры.
 */
static t_Game g_game = {0};

/* Function prototypes */
static void load_high_score(void);
static void save_high_score(void);
static void copy_field_with_figure(t_GameInfo *info);
static void copy_next_matrix(t_GameInfo *info);
static void copy_game_stats(t_GameInfo *info);

/**
 * @brief Инициализация игры.
 */
void game_init(void) {
  if (g_game.field) free_matrix(g_game.field, HEIGHT);
  if (g_game.next) free_matrix(g_game.next, FIG_Y);
  g_game.field = allocate_matrix(HEIGHT, WIDTH);
  g_game.next = allocate_matrix(FIG_Y, FIG_X);
  g_game.next_type = rand() % FIG_COUNT;
  load_high_score();
  g_game.score = 0;
  g_game.level = 1;
  g_game.speed = 600;
  g_game.pause = 0;
  g_game.game_over = 0;
  g_game.started = 0;
  pthread_mutex_init(&g_game.mutex, NULL);
}

/**
 * @brief Обработка ввода пользователя.
 * @param action Действие пользователя.
 * @param hold Флаг удержания (не используется).
 */
void userInput(t_UserAction action, bool hold) {
  (void)hold;
  pthread_mutex_lock(&g_game.mutex);
  fsm_handle_action(&g_game, action);
  pthread_mutex_unlock(&g_game.mutex);
}

/**
 * @brief Копирование игрового поля с наложением текущей фигуры.
 * @param info Указатель на состояние игры.
 */
static void copy_field_with_figure(t_GameInfo *info) {
  int i;
  int j;
  int x;
  int y;

  info->field = copy_matrix(g_game.field, HEIGHT, WIDTH);
  if (!info->field) return;
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      if (g_game.current_figure.shape[i][j]) {
        y = g_game.current_figure.y + i;
        x = g_game.current_figure.x + j;
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
          info->field[y][x] = g_game.current_figure.type + 1;
      }
      j++;
    }
    i++;
  }
}

/**
 * @brief Копирование следующей фигуры.
 * @param info Указатель на состояние игры.
 */
static void copy_next_matrix(t_GameInfo *info) {
  int i;
  int j;

  info->next = allocate_matrix(FIG_Y, FIG_X);
  if (!info->next) return;
  i = 0;
  while (i < FIG_Y) {
    j = 0;
    while (j < FIG_X) {
      if (g_game.next[i][j])
        info->next[i][j] = g_game.next_type + 1;
      else
        info->next[i][j] = 0;
      j++;
    }
    i++;
  }
}

/**
 * @brief Копирование игровой статистики.
 * @param info Указатель на состояние игры.
 */
static void copy_game_stats(t_GameInfo *info) {
  info->score = g_game.score;
  info->high_score = g_game.high_score;
  info->level = g_game.level;
  info->pause = g_game.pause;
  info->speed = g_game.speed;
}

/**
 * @brief Получение текущего состояния игры для фронтэнда.
 * @return Структура с копией данных.
 */
t_GameInfo updateCurrentState(void) {
  t_GameInfo info;

  pthread_mutex_lock(&g_game.mutex);
  copy_field_with_figure(&info);
  copy_next_matrix(&info);
  copy_game_stats(&info);
  if (g_game.score > g_game.high_score) {
    g_game.high_score = g_game.score;
    save_high_score();
  }
  pthread_mutex_unlock(&g_game.mutex);
  return (info);
}

/**
 * @brief Проверка на завершение игры.
 * @return 1 если игра закончена, 0 если нет.
 */
int game_over(void) { return (g_game.game_over); }

/**
 * @brief Загрузка Рекорда из файла.
 */
static void load_high_score(void) {
  FILE *file;

  file = fopen("highscore.txt", "r");
  if (file) {
    fscanf(file, "%d", &g_game.high_score);
    fclose(file);
  } else
    g_game.high_score = 0;
}

/**
 * @brief Сохранение рекорда в файл.
 */
static void save_high_score(void) {
  FILE *file;

  file = fopen("highscore.txt", "w");
  if (file) {
    fprintf(file, "%d", g_game.high_score);
    fclose(file);
  }
}

/**
 * @brief Проверка запущена ли игра.
 * @return 1 если игра запущена, 0 если нет.
 */
int game_started(void) { return g_game.started; }

/**
 * @brief Освобождение ресурсов игры и потоков.
 */
void game_destroy(void) {
  if (g_game.field) {
    free_matrix(g_game.field, HEIGHT);
    g_game.field = NULL;
  }
  if (g_game.next) {
    free_matrix(g_game.next, FIG_Y);
    g_game.next = NULL;
  }
  pthread_mutex_destroy(&g_game.mutex);
}