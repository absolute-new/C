#			Target
TARGET		= seek_io

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror -std=c99

#			Dirs
SRCS_PATH	= ./src/
BUILD_PATH	= ./build/
OBJS_PATH	= ./build/objects/

#			Sources
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Objects
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)


all: $(TARGET)

$(TARGET): $(OBJS) main.o
	$(CC) $(CCFLAGS) $(OBJS) $(OBJS_PATH)main.o -o $(BUILD_PATH)$@

main.o: main.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -I$(SRCS_PATH) -c main.c -o $(OBJS_PATH)main.o

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(BUILD_PATH)

re: fclean all


.PHONY: all clean fclean re
