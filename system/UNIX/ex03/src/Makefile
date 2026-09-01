#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

#			Dirs
SRCS_PATH	= ./
OBJS_PATH	= ../build/objects/

#			Sources
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Objects
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

all: $(OBJS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@
