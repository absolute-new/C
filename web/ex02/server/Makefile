#			Program NAME
NAME	= server

#			Compiler
CC		= gcc
CCFLAGS	= -Wall -Werror -Wextra

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./objects/
INCL_PATH	= ./include/

#			Source files
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Objects files
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

#			Colors
RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

#			Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CCFLAGS) -I$(INCL_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED) Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all


.PHONY: all clean fclean re