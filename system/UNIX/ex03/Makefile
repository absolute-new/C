#			TARGET
TARGET		= filehandler

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

#			Dirs
BUILD_PATH	= ./build/
SRCS_PATH	= ./
OBJS_PATH	= ./build/objects/
INCL_PATH	= /src/

#			Sources
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#			Objects
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

all: $(TARGET)

$(TARGET): $(OBJS) SRC_OBJS
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CCFLAGS) -I./src $(wildcard $(OBJS_PATH)*.o) -o $(BUILD_PATH)$@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -I./src -c $< -o $@

SRC_OBJS:
	$(MAKE) -C src

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(BUILD_PATH)

re: fclean all


.PHONY: all clean fclean re