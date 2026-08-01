#			OS Win/Lin
ifeq ($(OS), Windows_NT)
	RM			:= del /Q
	EXT			:= .exe
else
	RM			:= rm -f
	EXT			:=
endif

#			Programm name
NAME		= nuke$(EXT)

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

#			Directories
SRCS_PATH	= ./
INCL_PATH	= .
OBJS_PATH	= ./objects/

#			Source files
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

#			Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CCFLAGS) -I$(INCL_PATH) -c $< -o $@

clean:
	@$(RM) $(OBJS_PATH)*.o
	@rmdir $(OBJS_PATH) 2>/dev/null || true

fclean: clean
	@$(RM) $(NAME)

.PHONY: all clean fclean