##
## EPITECH PROJECT, 2022
## game_engine
## File description:
## Makefile
##

PROGRAM_NAME	?=	demo

CC	:=	g++

EXTENSION	:=	.cpp

TESTS_DIR	:=	tests/

TEST_SRC	:=	$(shell find $(TESTS_DIR) -name "*$(EXTENSION)" -type f)

TEST_CFLAGS ?=

TEST_LDFLAGS	?=

SRC	:=	$(shell find src -name "*$(EXTENSION)" -type f)

SRC_NO_MAIN	:=	$(shell find src -name "*$(EXTENSION)" -type f | \
				grep -v main.cpp | grep -v src/demo)

OBJ	:=	$(patsubst src/%$(EXTENSION), obj/%.o, $(SRC))

TEST_OBJ	:=	$(patsubst src/%$(EXTENSION), obj/%.o, $(SRC_NO_MAIN)) \
				$(patsubst tests/%$(EXTENSION), obj/tests/%.o, $(TEST_SRC))

CFLAGS	?=	-std=c++2a -Wall -Wextra -Wshadow -Wpedantic -Iinclude -O3\
			$(TEST_CFLAGS) -DLINUX

LDFLAGS	?=	-lsfml-graphics -lsfml-window -lsfml-system $(TEST_LDFLAGS)

DEPENDENCIES	:=	dependencies.d
ECHO	:=	echo
PROGRAM_NAME	?=	$(PROGRAM_NAME:.exe=.out)

all: $(DEPENDENCIES) $(PROGRAM_NAME)

run: MAKEFLAGS += --silent
run:
	@$(MAKE) all
	@$(MAKE) execute

execute:
	@echo "\033[1;32mRunning $(PROGRAM_NAME)...\033[0m"
	@./$(PROGRAM_NAME)

$(DEPENDENCIES): $(SRC)
	@$(ECHO) "\033[1;32mGenerating dependencies...\033[0m"
	@$(RM) $@
	@$(CC) $(CFLAGS) -MT"$(patsubst src/%$(EXTENSION), obj/%.o, $<)" \
	-MM $^ >> $@;

include $(DEPENDENCIES)
obj/%.o: src/%$(EXTENSION)
	@$(ECHO) "\033[34mCompiling $<\033[0m"
	@mkdir -p $$($(ECHO) $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $@ $(CFLAGS)

$(PROGRAM_NAME): $(DEPENDENCIES) $(OBJ)
	@$(ECHO) "\033[1;36mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(PROGRAM_NAME) $(LDFLAGS) $(CFLAGS)

clean:
	@$(ECHO) "\033[1;31mCleaning objects...\033[0m"
	@$(RM) -r obj
	@$(ECHO) "\033[1;31mCleaning dependencies...\033[0m"
	@$(RM) $(DEPENDENCIES)

clean_gcovr:
	@$(ECHO) "\033[1;31mCleaning gcovr...\033[0m"
	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) *.gcov

fclean: clean clean_gcovr
	@$(ECHO) "\033[1;31mCleaning executable...\033[0m"
	@$(RM) $(PROGRAM_NAME)

re: fclean
	@$(MAKE) --no-print-directory all


tests_run: export PROGRAM_NAME = unit_tests
tests_run: MAKEFLAGS += --no-print-directory
tests_run:
	@$(MAKE) tests_build
	@$(MAKE) execute
	@$(MAKE) coverage
	$(RM) $(PROGRAM_NAME)

make_test_obj: $(patsubst %, %.test, $(TEST_OBJ))

tests_build: export PROGRAM_NAME = unit_tests
tests_build: export CFLAGS += --coverage -O0
tests_build: export LDFLAGS += -lcriterion
ifeq (${origin DISPLAY}, environment)
tests_build: export CFLAGS += -DDISPLAY
endif
tests_build:
	@$(MAKE) fclean
	@$(MAKE) $(TEST_OBJ)
	@echo "\033[1;36mLinking tests...\033[0m"
	@$(CC) $(TEST_OBJ) \
	-o $(PROGRAM_NAME) $(CFLAGS) $(TEST_CFLAGS) $(LDFLAGS)

coverage:
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR)
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR) -b

debug: export CFLAGS += -g3
debug: re

.phony: all clean fclean re debug run tests_run tests_build execute
