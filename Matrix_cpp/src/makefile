CC = gcc
G++ = g++
GFLAGS = -Wall -Werror -Wextra
CFLAGS = -std=c++17 -Wall -Werror -Wextra
OBJECT = lib/s21_matrix_oop.a
LIBSFLAGS = -lgtest_main -lgtest
TEST_FILES = testfiles/*.cpp
SOURCE = functions/s21_*.cpp
VALGRIND_LOG =  valgrind --tool=memcheck --leak-check=yes -q --log-file="log_valgrind.txt"
VALGRIND =  valgrind --tool=memcheck --leak-check=yes
CLANG = clang-format -style=Google

all: clean $(OBJECT)

$(OBJECT): clean
	mkdir ./lib
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar r $(OBJECT) *.o
	ranlib $(OBJECT)
	rm -rf *.o

test: clean_test $(OBJECT)
	$(G++) $(GFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	./test

test_valgrind: clean_test $(OBJECT)
	$(G++) $(GFLAGS) -o test $(TEST_FILES) $(OBJECT) $(LIBSFLAGS)
	$(VALGRIND) ./test

clean: clean_report clean_test
	rm -rf $(OBJECT) *.o main ./lib

clean_test:
	rm -rf test

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

checkformat:
	$(CLANG) -n functions/*.cpp functions/*.h
	$(CLANG) -n testfiles/*.cpp testfiles/*.h

setformat:
	$(CLANG) -i functions/*.cpp functions/*.h
	$(CLANG) -i testfiles/*.cpp testfiles/*.h

report: gcov_report

openreport:
	firefox GCOVRreport/gcov_report.html

gcov_report: clean_test clean_report $(OBJECT)
	g++ --coverage $(SOURCE) ${TEST_FILES} -o test $(OBJECT) $(LIBSFLAGS)
	./test
	gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda

help:
	@echo
	@echo "		Hello, world! Welcome to S21_MATRIX_CPP!"
	@echo
	@echo "		Usage: make [option]"
	@echo "		<test> 						Run tests"
	@echo "		<test_valgrind> 			Run tests with valgrind"
	@echo "		<report> or <gcov_report> 	Builds GCOVr report"
	@echo "		<openreport> 		 		Use it after building report for open page on firefox browser"
	@echo "		<checkformat> 				Make style check based of Google-style"
	@echo


