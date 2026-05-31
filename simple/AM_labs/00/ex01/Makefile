#			Program name
NAME		= fibonacci

#			Compiler
CXX			= gcc
CXXFLAGS	= -Wall -Wextra -Werror

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#			Source files
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

#			RULES
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re