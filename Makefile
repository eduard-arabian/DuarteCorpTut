.PHONY: all test rebuild clean style mem

PROG=diccionario

CC=gcc
CFLAGS=-std=c11 -g -Wall -Werror -Wextra

SOURCES=*.c
HEADERS=*.h
OBJ=*.o

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit -lrt
endif

GCDA=*.gcda
GCNO=*.gcno
GCOV=*.gcov

STYLE_CHECK=$(shell find . -name '*.c' && find . -name '*.h')
FIND_CHECK=$(shell pkg-config --cflags --libs check)

all: $(PROG)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(PROG):
	$(CC) $(SOURCES) -c $(CFLAGS)
	$(CC) $(OBJ) -o $(PROG)

style:
	clang-format -style=google -i $(STYLE_CHECK)
	python3 ./cpplint.py --extension=c,h $(STYLE_CHECK)
	cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem $(STYLE_CHECK)

mem: rebuild
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(PROG)
else
	leaks --atExit -- ./$(PROG)
endif

clean:
	rm -rf $(PROG) *.a *.o

rebuild: clean all
