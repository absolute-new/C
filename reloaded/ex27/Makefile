# **************************************************************************** #
#                                                                              #
#                                                     ########        #####    #
#    Makefile                                       #+#    #+#       #+#:#     #
#                                                        #:#      ##  #:#      #
#    By: absolute <absolute>                          #+#      +#    #:#       #
#                                                  #+#              #+#        #
#    Created: 2025/09/13 04:57:14 by absolute     ##               #+#         #
#    Updated: 2025/09/13 04:57:15 by absolute     ########        ###          #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ft_display_file.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re