


#			OS
ifeq ($(OS), Windows_NT)
	EXT		= .exe
	LIBS	= -lws2_32
else
	EXT		=
	LIBS	=
endif

#			Target
NAME		= showip$(EXT)

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

#			Sources
SRCS		= $(wildcard ./*.c)

#			Rules
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	rm -f $(NAME)


.PHONY: all clean