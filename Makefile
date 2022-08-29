CC := g++

FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef          \
		 -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations     \
		 -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++       \
		 -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion  \
		 -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2        \
		 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers       \
		 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
		 -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel          \
		 -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

FLAGS_OPT := -O3

DIR_BUILD := .\build

EXEC_FILE := quadratic.exe

TEST_FILE := test.exe


all: test

test: build_dir $(DIR_BUILD)/$(TEST_FILE)

release: build_dir $(DIR_BUILD)/$(EXEC_FILE)

$(DIR_BUILD)/$(EXEC_FILE): build/square.o build/quadratic_equation.o build/unit_test.o build/io.o
	$(CC) $(FLAGS) $(FLAGS_OPT) $(DIR_BUILD)/square.o $(DIR_BUILD)/quadratic_equation.o $(DIR_BUILD)/unit_test.o $(DIR_BUILD)/io.o -o $(DIR_BUILD)/$(EXEC_FILE)

$(DIR_BUILD)/$(TEST_FILE): build/square_test.o build/quadratic_equation.o build/unit_test.o build/io.o
	$(CC) $(FLAGS) $(DIR_BUILD)/square_test.o $(DIR_BUILD)/quadratic_equation.o $(DIR_BUILD)/unit_test.o $(DIR_BUILD)/io.o -o $(DIR_BUILD)/$(TEST_FILE)

build/square_test.o: square.cpp
	$(CC) $(FLAGS) -c $< -D TEST -o ./$@

build/square.o: square.cpp
	$(CC) $(FLAGS) -c $< -o ./$@

build/quadratic_equation.o: ./src/quadratic_equation.cpp
	$(CC) $(FLAGS) -c $< -o ./$@

build/unit_test.o: ./test/unit_test.cpp
	$(CC) $(FLAGS) -c $< -o ./$@

build/io.o: ./src/io.cpp
	$(CC) $(FLAGS) -c $< -o ./$@

clean: build_dir 
	del $(DIR_BUILD)\square_test.o
	del $(DIR_BUILD)\square.o
	del $(DIR_BUILD)\quadratic_equation.o
	del $(DIR_BUILD)\unit_test.o
	del $(DIR_BUILD)\io.o

ifneq ("$(wildcard ./build)","./build") 
build_dir:
	mkdir build	
else
build_dir:

endif