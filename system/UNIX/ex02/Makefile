#			Target
TARGET		= copy_file

#		Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

#		Directories
SRCS_PATH	= ./
OBJS_PATH	= ./build/objects/
BUILD_PATH	= ./build/

#		Sources files
SRCS		= $(wildcard $(SRCS_PATH)*.c)

#		Objects files
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJS_PATH)%.o)

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(BUILD_PATH)$@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(BUILD_PATH)


.PHONY: all clean fclean