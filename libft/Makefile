NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c \
       # Добавьте остальные файлы Part 1

# Bonus part (если нужно)
#BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
             ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
             ft_lstmap.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

# Main target
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Libft compiled successfully!$(NC)"

# Compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Bonus target
bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)Libft with bonus compiled successfully!$(NC)"

# Clean object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)Object files removed$(NC)"

# Clean everything
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Libft removed$(NC)"

# Recompile
re: fclean all

# Prevent conflicts with files named like targets
.PHONY: all clean fclean re bonus