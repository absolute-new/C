#			Program name
NAME		= libftprint.a

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#			Source files
SRCS		= ft_printf.c ft_parse_flags.c ft_printf_utils.c	\
				ft_puthex.c	ft_putchar_flags.c ft_putchar.c		\
				ft_puthex_flags.c ft_putnbr.c ft_putnbr_flags.c	\
				ft_putptr_flags.c ft_putptr.c ft_putstr_flags.c	\
				ft_putstr.c ft_putunsigned_flags.c				\
				ft_putunsigned.c

#			Object files
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

#			Colors for output
RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

#			RULES
all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created sucessfully$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CCFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./test
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

test: re
	@$(CC) tests/main.c $(NAME) -o test
	@./test