#			Program name
NAME		= tetris
LIB_NAME	= tetris_lib

#			Compiler
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror -pthread
LDFLAGS		= -lncurses
VG_FLAGS	= --leak-check=full --track-origins=yes --show-leak-kinds=all
TEST_LIBS	= -lcheck -lm -lpthread -lrt -lsubunit

#			Directories
OBJS_PATH	= ./build/obj/
TETRIS_PATH	= ./brick_game/tetris/
GUI_PATH	= ./gui/cli/
TEST_PATH	= ./tests/
INST_PATH	= ~/.local/tetris/
LIB_PATH	= ./build/lib/
BUILD_PATH	= ./build/
BP_TS_PATH	= ./build/test/
GCOV_PATH	= ./build/report/

#			Source files Tetris
TETRIS_SRCS	= tetris.c game_logic.c figure.c memory.c fsm.c wall_kick.c
TETRIS_SRCS	:= $(addprefix $(TETRIS_PATH), $(TETRIS_SRCS))

#			Source files Gui
GUI_SRCS	= main.c frontend.c input.c threads.c
GUI_SRCS	:= $(addprefix $(GUI_PATH), $(GUI_SRCS))

#			All source files
SRCS		= $(TETRIS_SRCS) $(GUI_SRCS)

#			Object files
GUI_OBJS	= $(GUI_SRCS:$(GUI_PATH)%.c=$(OBJS_PATH)%.o)
LIB_OBJS	= $(TETRIS_SRCS:$(TETRIS_PATH)%.c=$(OBJS_PATH)%.o)

LIB_FILE	= $(LIB_PATH)lib$(LIB_NAME).a

#			Source files test
TEST_SRCS	= suite.c test_check_collision.c utils.c		\
				test_try_move.c test_try_rotate.c			\
				test_attach_figure.c test_clear_lines.c		\
				test_spawn_figure.c test_wall_kick.c		\
				test_figure.c test_fsm.c test_tetris.c

TEST_SRCS	:= $(addprefix $(TEST_PATH), $(TEST_SRCS))

#			Colors for output
RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m
CYAN		= \033[1;35m

#			RULES
$(NAME): $(LIB_FILE) $(GUI_OBJS)
	@$(CC) $(CCFLAGS) $(GUI_OBJS) -L$(LIB_PATH) -l$(LIB_NAME) -o $@ $(LDFLAGS)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(LIB_FILE): $(LIB_OBJS)
	@mkdir -p $(LIB_PATH)
	@ar rcs $@ $^
	@echo "$(GREEN)Static library $(LIB_NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(TETRIS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CCFLAGS) -I$(TETRIS_PATH) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(RESET)"

$(OBJS_PATH)%.o: $(GUI_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CCFLAGS) -I$(GUI_PATH) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(RESET)"

$(BP_TS_PATH)test_tetris: $(TEST_SRCS) $(TETRIS_SRCS)
	@mkdir -p $(BP_TS_PATH)
	@echo "$(GREEN)Running tests...$(RESET)"
	@$(CC) $(CCFLAGS) -I$(TETRIS_PATH) -I$(TEST_PATH)	\
	$(TEST_SRCS) $(TETRIS_PATH)game_logic.c 			\
	$(TETRIS_PATH)figure.c $(TETRIS_PATH)wall_kick.c	\
	$(TETRIS_PATH)memory.c $(TETRIS_PATH)fsm.c			\
	$(TETRIS_PATH)tetris.c								\
		-o $(BP_TS_PATH)test_tetris $(TEST_LIBS)


all: $(NAME)

test: $(BP_TS_PATH)test_tetris	
	@ ./$(BP_TS_PATH)test_tetris
	@echo "$(GREEN)All tests passed$(RESET)"

clean:
	@rm -rf $(OBJS_PATH)
	@find . -name "*gcda" -delete
	@find . -name "*.gcno" -delete
	@echo "$(RED)Build files removed$(RESET)"

fclean: clean
	@rm -rf $(BUILD_PATH)
	@rm -f $(NAME)
	@rm -rf docs
	@rm -f highscore.txt
	@rm -f tetris.tar.gz
	@echo "$(RED)$(NAME) removed$(RESET)"
	@echo "$(RED)docs removed$(RESET)"
	@echo "$(RED)highscore.txt tetris.tar.gz removed$(RESET)"

re: fclean all

install: all
	@mkdir -p $(INST_PATH)
	@cp $(NAME) $(INST_PATH)
	@echo "$(GREEN)Installed to $(INST_PATH)$(NAME)$(RESET)"

uninstall:
	@rm -rf $(INST_PATH)
	@echo "$(RED)Uninstalled from $(INST_PATH)$(NAME)"

dvi:
	@doxygen Doxyfile
	@echo "$(GREEN) Docs generating /docs/html/index.html$(RESET)"

dist: clean
	@tar -czf $(NAME).tar.gz *
	@echo "$(GREEN)Distribution created $(NAME).tar.gz$(RESET)"

gcov_report: fclean $(LIB_OBJS)
	@echo "$(CYAN)Generating coverage report ...$(RESET)"
	@mkdir -p $(GCOV_PATH)
	@$(CC) $(CCFLAGS) --coverage -I$(TETRIS_PATH) -I$(TEST_PATH)			\
		$(TETRIS_SRCS) $(TEST_SRCS) -o $(OBJS_PATH)test_coverage			\
		$(TEST_LIBS) $(LDFLAGS)
	@./$(OBJS_PATH)test_coverage
	@lcov --capture --directory . --output-file $(GCOV_PATH)coverage.info	\
		--quiet
	@lcov --remove $(GCOV_PATH)coverage.info '*/tests/' --output-file		\
		$(GCOV_PATH)coverage_filtered_info --quiet							
	@genhtml $(GCOV_PATH)coverage_filtered_info --output-directory 			\
		$(GCOV_PATH) --quiet
	@echo "$(GREEN)Coverage report: $(GCOV_PATH)index.html$(RESET)"

test_valgrind: $(BP_TS_PATH)test_tetris
	@echo "$(CYAN)Running Valgrind check...$(RESET)"
	@valgrind $(VG_FLAGS) ./$(BP_TS_PATH)test_tetris 2>$(BP_TS_PATH)valgrind.raw.txt
	@echo ""
	@grep "ERROR SUMMARY" $(BP_TS_PATH)valgrind.raw.txt | sed 's/==[0-9]*== //'
	@if grep -q "ERROR SUMMARY: 0 errors" $(BP_TS_PATH)valgrind.raw.txt && 		\
		grep -q "definitely lost: 0 bytes" $(BP_TS_PATH)valgrind.raw.txt &&		\
		grep -q "indirectly lost: 0 bytes" $(BP_TS_PATH)valgrind.raw.txt; then	\
		echo "$(GREEN)No memory errors$(RESET)";								\
		exit 0;																	\
	else																		\
		echo "$(RED) Memory errors found!$(RESET)"; 							\
		exit 1;																	\
	fi

clang-n: $(SRCS)
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -n $$(find . -name "*.c")
	@rm -f ./.clang-format

.PHONY: all test clean fclean re install uninstall dvi dist gcov_report test_valgrind clang-n
