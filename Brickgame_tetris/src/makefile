CC = gcc
PROG_NAME = brickgame
VER = 1.01
CFLAGS = -I inc -std=c11 -Wall -Werror -Wextra
OBJECT = lib/s21_brick_game_v1.0.a
LIBSFLAGS = -lcheck -lncurses -lm -lsubunit
TEST_FILES = testfiles/*.c
SOURCE_1 = brickgame/tetris/*.c
SOURCE_2 = gui/cli/*.c
MAIN = brickgame/main/brickgame.c
VALGRIND_LOG =  valgrind --tool=memcheck --leak-check=yes -q --log-file="log_valgrind.txt"
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean $(OBJECT)

$(OBJECT): clean
	$(CC) $(CFLAGS) -c $(SOURCE_1)
	$(CC) $(CFLAGS) -c $(SOURCE_2)
	ar r $(OBJECT) *.o
	ranlib $(OBJECT)
	rm -rf *.o

install: clean $(OBJECT)
	mkdir ./bin
	$(CC) $(CFLAGS) -o bin/game $(MAIN) $(OBJECT) $(LIBSFLAGS)

uninstall:
	rm -rf ./bin/game

game_valgrind: clean $(OBJECT)
	$(CC) $(CFLAGS) -o game $(MAIN) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND_LOG) ./bin/game

test: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	./test

test_valgrind: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND) ./test

clean: clean_report clean_test
	rm -rf $(OBJECT) *.o bin/game ./dist ./bin

clean_test:
	rm -rf test

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

play:
	./bin/game

dvi:
	mkdir -p dvi
	texi2dvi readme.texi --dvi -o readme.dvi
	mv readme.* dvi
	mv dvi/readme.txt .
	mv dvi/readme.texi .

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

report: gcov_report

openreport:
	firefox GCOVRreport/gcov_report.html

gcov_report: clean_test clean_report $(OBJECT)
	gcc -I inc --coverage $(SOURCE_1) $(SOURCE_2) ${TEST_FILES} -o test $(OBJECT) $(LIBSFLAGS)
	./test
	~/.local/bin/gcovr -r . --html-details -o gcov_report.html
	# gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda

help:
	@echo
	@echo "		Hello, world! Welcome to s21_brick_game_v1.0!"
	@echo
	@echo "		Usage: make [option]"
	@echo "		<test> 				Run tests"
	@echo "		<test_valgrind> 		Run tests with valgrind"
	@echo "		<report> or <gcov_report> 	Builds GCOVr report"
	@echo "		<openreport> 		 	Use it after building report for open page on firefox browser"
	@echo "		<checkformat> 			Make style check based of Google-style"
	@echo


