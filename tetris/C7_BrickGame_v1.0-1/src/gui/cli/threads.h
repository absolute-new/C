/**
 * @file threads.h
 * @brief Многопоточность.
 */
#ifndef THREADS_H
# define THREADS_H

# include "input.h"

# define THREAD_COUNT 3	/**< Количество потоков для барьера. */

void	start_game_threads(void);
void	stop_game_threads(void);
void	wait_game_threads(void);

#endif