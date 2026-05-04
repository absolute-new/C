/**
 * @file frontend.c
 * @brief Реализация фронтэнд Тетриса.
 */
#include "frontend.h"

/* Function prototypes */
static void draw_start_screen(void);
static void draw_field(t_GameInfo info);
static void draw_info_panel_bg(void);
static void draw_info_figure(t_GameInfo info);
static void draw_info_text(t_GameInfo info);

/**
 * @brief Инициализация ncurse и цветов.
 */
void init_frontend(void) {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  timeout(0);
  keypad(stdscr, TRUE);
  start_color();
  init_pair(RED, COLOR_BLACK, COLOR_RED);
  init_pair(PINK, COLOR_BLACK, 213);
  init_pair(BLUE, COLOR_BLACK, 12);
  init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
  init_pair(MAGENTA, COLOR_BLACK, 5);
  init_pair(ORANGE, COLOR_BLACK, 208);
  init_pair(YELLOW, COLOR_BLACK, 226);
  init_pair(FIELD, COLOR_BLACK, COLOR_WHITE);
  init_pair(INFO, COLOR_RED, COLOR_WHITE);
  clear();
  refresh();
}

/**
 * @brief Очистка ресурсов ncurses.
 */
void cleanup_frontend(void) { endwin(); }

/**
 * @brief Отрисовка стартового экрана.
 */
static void draw_start_screen(void) {
  attron(COLOR_PAIR(INFO) | A_BOLD | A_BLINK);
  mvprintw(HEIGHT / 2 - 2, (WIDTH * 2 - strlen("TETRIS") + 1) / 2, "TETRIS");
  mvprintw(HEIGHT / 2 + 1, (WIDTH * 2 - 11) / 2 + 1, "PRESS START");
  attroff(COLOR_PAIR(INFO) | A_BOLD | A_BLINK);
}

/**
 * @brief Отрисовка игрового поля.
 * @param info Копия состояния игры.
 */
static void draw_field(t_GameInfo info) {
  int i;
  int j;

  i = 0;
  while (i < HEIGHT) {
    j = 0;
    while (j < WIDTH) {
      move(i + 1, j * 2 + 1);
      if (info.field && info.field[i][j]) {
        PRINT_BLOCK(info.field[i][j]);
      } else {
        PRINT_BLOCK(FIELD);
      }
      j++;
    }
    i++;
  }
}

/**
 * @brief Отрисовка фона информационной панели.
 */
static void draw_info_panel_bg(void) {
  int i;

  i = 1;
  attron(COLOR_PAIR(FIELD));
  while (i < PANEL_START - 1) {
    move(i, PANEL_START);
    printw("                    ");
    i++;
  }
  attroff(COLOR_PAIR(FIELD));
}

/**
 * @brief Отрисовка следующей фигуры.
 * @param info Копия состояния игры.
 */
static void draw_info_figure(t_GameInfo info) {
  int i;
  int j;

  if (info.next) {
    i = 0;
    while (i < FIG_Y) {
      j = 0;
      while (j < FIG_X) {
        move(10 + i, 28 + j * 2);
        if (info.next[i][j]) {
          PRINT_BLOCK(info.next[i][j]);
        } else {
          PRINT_BLOCK(FIELD);
        }
        j++;
      }
      i++;
    }
  }
}

/**
 * @brief Отрисовка текстовой информации.
 * @param info Копия состояния игры.
 */
static void draw_info_text(t_GameInfo info) {
  attron(COLOR_PAIR(INFO) | A_BOLD);
  mvprintw(2, CENTER("SCORE"), "SCORE");
  mvprintw(3, CENTER("00000"), "%05d", info.score);
  mvprintw(5, CENTER("HI-SCORE"), "HI-SCORE");
  mvprintw(6, CENTER("00000"), "%05d", info.high_score);
  mvprintw(9, CENTER("NEXT"), "NEXT");
  mvprintw(15, CENTER("SPEED"), "SPEED");
  mvprintw(16, CENTER("000000"), "%03d ms", info.speed);
  mvprintw(18, CENTER("LEVEL"), "LEVEL");
  mvprintw(19, CENTER("00"), "%02d", info.level);
  if (info.pause) {
    attron(A_BLINK);
    mvprintw(15, CENTER("PAUSED"), "PAUSED");
    attroff(A_BLINK);
  }
  attroff(COLOR_PAIR(INFO) | A_BOLD);
}

/**
 * @brief Отрисовка "GAME OVER".
 */
void draw_game_over(void) {
  if (game_over()) {
    attron(COLOR_PAIR(INFO) | A_BOLD | A_BLINK);
    mvprintw(HEIGHT / 2, 6, "GAME OVER");
    attroff(COLOR_PAIR(INFO) | A_BOLD | A_BLINK);
  }
}

/**
 * @brief Полная отрисовка игры.
 * @param info Копия состояния игры.
 */
void render_game(t_GameInfo info) {
  refresh();
  draw_field(info);
  draw_info_panel_bg();
  draw_info_figure(info);
  draw_info_text(info);
  if (!game_started()) {
    draw_start_screen();
  }
}
