#			Program name
NAME		= pipex

#			Compiler
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#			Source files
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

#			Valgrind
VG			= valgrind
VGFLAGS		= --leak-check=full --show-leak-kinds=all

#			Colors for output
RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

#			RULES
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

leaks: re
	@echo "Hello world" > infile
	@echo "Test line 1" >> infile
	@echo "Test line 2" >> infile
	@$(VG) $(VGFLAGS) ./$(NAME) infile "cat" "wc -l" outfile
	@rm -f infile
	@rm -f outfile

.PHONY: all clean fclean re leaks