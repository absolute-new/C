NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c     \
	   		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c  \
      		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c     \
	  		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c   \
       		ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c  \
       		ft_strjoin.c ft_split.c ft_itoa.c ft_strtrim.c ft_putchar_fd.c   \
	   		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c      \
	   		ft_strtrim.c ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_islower.c \
			ft_isspace.c ft_isupper.c ft_isxdigit.c ft_itoa_base.c           \
			ft_strcapitalize.c ft_strcasecmp.c ft_strcasestr.c               \
			ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c      \
			ft_strlowcase.c \

BONUS_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c  \
            ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
            ft_lstmap.c                                                \

# Object files
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
NC			= \033[0m

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