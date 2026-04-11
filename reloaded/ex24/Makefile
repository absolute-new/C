# **************************************************************************** #
#                                                                              #
#                                                     ########        #####    #
#    Makefile                                       #+#    #+#       #+#:#     #
#                                                        #:#      ##  #:#      #
#    By: absolute <absolute>                          #+#      +#    #:#       #
#                                                  #+#              #+#        #
#    Created: 2025/09/12 06:54:01 by absolute     ##               #+#         #
#    Updated: 2025/09/12 06:54:03 by absolute     ########        ###          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c \
	  ft_strlen.c ft_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all