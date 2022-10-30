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

CFLAGS	:=	-std=c++2a -Wall -Wextra -Wshadow -Wpedantic -Iinclude -O3\
			$(TEST_CFLAGS)

LDFLAGS	:=	-lsfml-graphics -lsfml-window -lsfml-system $(TEST_LDFLAGS)

ifeq ($(OS),Windows_NT)
DEPENDENCIES	:=	dependencies.win.d
EXTERNAL_LIBS	:=	C:/lib/SFML-2.5.1/
DLLS	:=	$(shell find $(EXTERNAL_LIBS)/bin -name "*.dll" -type f)
LDFLAGS	+=	$(foreach lib, $(EXTERNAL_LIBS), -L"$(lib)/lib")
CFLAGS	+=	$(foreach lib, $(EXTERNAL_LIBS), -I"$(lib)/include")
CFLAGS	+=	-DWINDOWS
ECHO	:=	echo -e
PROGRAM_NAME	:=	$(PROGRAM_NAME:.out=.exe)

else
DEPENDENCIES	?=	dependencies.unix.d
CFLAGS	+=	-DLINUX
ECHO	?=	echo
PROGRAM_NAME	?=	$(PROGRAM_NAME:.exe=.out)

endif

all: $(DEPENDENCIES) $(PROGRAM_NAME)

run: all execute

execute:
	@echo "\033[1;32mRunning $(PROGRAM_NAME)...\033[0m"
	@./$(PROGRAM_NAME)

$(DEPENDENCIES): $(SRC)
	@$(ECHO) "\033[1;32mGenerating dependencies...\033[0m"
	@$(RM) $@
	@$(CC) $(CFLAGS) -MT"$(patsubst src/%$(EXTENSION), obj/%.o, $<)" \
	-MM $^ >> $@;

ifneq (${DISPLAY},)
obj/tests/%.o.test: CFLAGS += -DDISPLAY
endif
obj/tests/%.o.test: tests/%$(EXTENSION)
	@$(ECHO) "\033[2;32mCompiling $<\033[0m"
	@mkdir -p $$($(ECHO) $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $(patsubst %.test, %, $@) $(CFLAGS) --coverage -O0

obj/%.o.test: src/%$(EXTENSION)
	@$(ECHO) "\033[34mCompiling $<\033[0m"
	@mkdir -p $$($(ECHO) $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $(patsubst %.test, %, $@) $(CFLAGS) --coverage -O0

include $(DEPENDENCIES)
obj/%.o: src/%$(EXTENSION)
	@$(ECHO) "\033[34mCompiling $<\033[0m"
	@mkdir -p $$($(ECHO) $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $@ $(CFLAGS)

make_obj:
	@$(MAKE) --no-print-directory -s --jobs=$(shell nproc) $(OBJ)

ifeq ($(OS),Windows_NT)
$(PROGRAM_NAME): make_obj
	@$(ECHO) "\033[36;1mCopying dlls to $(CURDIR)\033[0m"
	@$(RM) $(wildcard $(CURDIR)/*.dll)
	@cp $(DLLS) $(CURDIR)
	@$(ECHO) "\033[1;36mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(PROGRAM_NAME) $(LDFLAGS) $(CFLAGS)
else
$(PROGRAM_NAME): make_obj
	@$(ECHO) "\033[1;36mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(PROGRAM_NAME) $(LDFLAGS) $(CFLAGS)
endif

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

re: fclean all

tests_run: PROGRAM_NAME = unit_tests
tests_run: tests_build execute coverage
	$(RM) $(PROGRAM_NAME)

make_test_obj:
	@$(MAKE) --jobs=$(shell nproc) --no-print-directory $(patsubst %, %.test, $(TEST_OBJ))

tests_build: export PROGRAM_NAME = unit_tests
tests_build: CFLAGS += --coverage -O0
tests_build: LDFLAGS += -lcriterion
tests_build: fclean make_test_obj
	@echo "\033[1;36mLinking tests...\033[0m"
	@$(CC) $(TEST_OBJ) \
	-o $(PROGRAM_NAME) $(CFLAGS) $(TEST_CFLAGS) $(LDFLAGS)

coverage:
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR)
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR) -b

debug: CFLAGS += -g3 -O0
debug: re

.phony: all clean fclean re debug run tests_run building_test execute
