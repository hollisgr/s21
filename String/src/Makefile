CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -pedantic
LIBSFLAGS = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
TEST_FILES = U-Test/*.c
SOURCE = functions/*.c
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean s21_string.a

s21_string.a: clean
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar r lib/s21_string.a *.o
	ranlib lib/s21_string.a
	rm -rf *.o

test: clean_test
	$(CC) $(CFLAGS) -o test $(TEST_FILES) lib/s21_string.a $(LIBSFLAGS)
	$(VALGRIND) ./test

clean: clean_report clean_test
	rm -rf lib/s21_string.a *.o

clean_test:
	rm -rf test

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

format:
	$(CLANG) -n functions/*.c functions/*.h
	$(CLANG) -n U-Test/*.c U-Test/*.h

report: gcov_report

gcov_report: clean_test clean_report
	gcc --coverage $(SOURCE) ${TEST_FILES} -o test lib/s21_string.a $(LIBSFLAGS)
	./test
	gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda
