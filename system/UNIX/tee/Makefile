#		TARGET
TARGET		= tee

#		Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror -std=c99

#		Dirs
BUILD_PATH	= ./build/
SRCS_PATH	= ./src/
OBJS_PATH	= $(BUILD_PATH)objects/

#		Srcs
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#		Objs
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)


all: $(TARGET)

$(TARGET): $(OBJS) main.o
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CCFLAGS) $(OBJS) $(BUILD_PATH)main.o -o $(BUILD_PATH)$@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CCFLAGS) -I./src -c main.c -o $(BUILD_PATH)main.o

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(BUILD_PATH)


.PHONY: all clean fclean