CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
OBJECT = lib/s21_decimal.a
LIBSFLAGS = -lcheck -lm -lsubunit -lrt -lpthread -D_GNU_SOURCE
TEST_FILES = testfiles/*.c
SOURCE = functions/s21_*.c
VALGRIND_LOG =  valgrind --tool=memcheck --leak-check=yes -q --log-file="log_valgrind.txt"
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean $(OBJECT)

$(OBJECT): clean
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar r $(OBJECT) *.o
	ranlib $(OBJECT)
	rm -rf *.o

test: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	./test

test_valgrind: clean_test $(OBJECT)
	$(CC) $(CFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND) ./test

clean: clean_report clean_test
	rm -rf $(OBJECT) *.o main

clean_test:
	rm -rf test

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

checkformat:
	$(CLANG) -n functions/*.c functions/*.h
	$(CLANG) -n testfiles/*.c testfiles/*.h

setformat:
	$(CLANG) -i functions/*.c functions/*.h
	$(CLANG) -i testfiles/*.c testfiles/*.h

report: gcov_report

openreport:
	firefox GCOVRreport/gcov_report.html

gcov_report: clean_test clean_report $(OBJECT)
	gcc --coverage $(SOURCE) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	./test
	gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda