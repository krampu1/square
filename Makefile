CC 	  := g++
FLUGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
		-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
		-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
		-Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
		-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
		-Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers \
		-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
		-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
		-Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

BUILDDIR := ./object_files
TESTDIR  := ./test

all: square.o quadratic_equation.o unit_test.o input_output.o
	$(CC) $(FLUGS) ./object_files/square.o ./object_files/quadratic_equation.o ./test/unit_test.o ./object_files/input_output.o -o square

square.o: square.cpp
	$(CC) $(FLUGS) -c $< -o $(BUILDDIR)/$@

quadratic_equation.o: ./body/quadratic_equation.cpp
	$(CC) $(FLUGS) -c $< -o $(BUILDDIR)/$@

unit_test.o: ./test/unit_test.cpp
	$(CC) $(FLUGS) -c $< -o $(TESTDIR)/$@

input_output.o: ./body/input_output.cpp
	$(CC) $(FLUGS) -c $< -o $(BUILDDIR)/$@

clean:
	del .\object_files\square.o
	del .\object_files\quadratic_equation.o
	del .\test\unit_test.o
	del .\object_files\input_output.o