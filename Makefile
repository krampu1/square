all:
	g++ square.cpp quadratic_equation.cpp unit_test.cpp -o square
debug:
	g++ square.cpp quadratic_equation.cpp unit_test.cpp -D TEST -o square