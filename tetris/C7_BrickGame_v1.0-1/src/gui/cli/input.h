/**
 * @file input.h
 * @brief Очередь действий пользователя.
 */
#ifndef INPUT_H
# define INPUT_H

# include "frontend.h"

void			init_queue(void);
void			push_action(t_UserAction action);
t_UserAction	pop_action(void);
t_UserAction	get_user_action(void);

#endif