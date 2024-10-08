CC = gcc
PROG_NAME = brickgame
VER = 1.01
CFLAGS = -I inc -std=c11 -Wall -Werror -Wextra
OBJECT = lib/s21_brick_game_v1.0.a
LIBSFLAGS = -lcheck -lncurses -lm -lsubunit
SOURCE_1 = brickgame/tetris/*.c
SOURCE_2 = gui/cli/*.c
MAIN = brickgame/main/brickgame.c
VALGRIND_LOG =  valgrind --tool=memcheck --leak-check=yes -q --log-file="log_valgrind.txt"
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean install

$(OBJECT): clean
	mkdir ./lib
	$(CC) $(CFLAGS) -c $(SOURCE_1)
	$(CC) $(CFLAGS) -c $(SOURCE_2)
	ar r $(OBJECT) *.o
	ranlib $(OBJECT)
	rm -rf *.o

install: clean $(OBJECT)
	mkdir ./bin
	$(CC) $(CFLAGS) -o bin/game $(MAIN) $(OBJECT) $(LIBSFLAGS)

uninstall:
	rm -rf ./bin

game_valgrind: clean $(OBJECT)
	$(CC) $(CFLAGS) -o game $(MAIN) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND_LOG) ./bin/game

clean:
	rm -rf $(OBJECT) *.o bin/game ./dist ./bin ./lib

play:
	./bin/game

dist: clean
	mkdir ./dist
	cp -a brickgame ./dist
	cp -a dvi ./dist
	cp -a gui ./dist
	cp -a materials ./dist
	cp -a inc ./dist
	cp -a lib ./dist
	cp -a testfiles ./dist
	cp -a brickgame.c ./dist
	cp -a game_stats.txt ./dist
	cp -a readme.texi ./dist
	cp -a makefile ./dist
	tar -czf $(PROG_NAME)_$(VER).tar.gz ./dist
	rm -rf ./dist

checkformat:
	$(CLANG) -n brickgame/tetris/*.c gui/cli/*.c
	$(CLANG) -n inc/*.h
	$(CLANG) -n testfiles/*.c testfiles/*.h

setformat:
	$(CLANG) -i brickgame/tetris/*.c gui/cli/*.c
	$(CLANG) -i inc/*.h
	$(CLANG) -i testfiles/*.c testfiles/*.h

