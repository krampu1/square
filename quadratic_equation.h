/** 
* \file quadratic_equation.h
* \brief quadratic equation header file
*/

#include <math.h>
#include <stdio.h>
#include <assert.h>

#define COLOR_RED "\x1B[31m"      ///< this line allows you to recolor the color of subsequent characters in the console to red

#define COLOR_GREEN "\x1B[32m"    ///< this line allows you to recolor the color of subsequent characters in the console to green

#define END_COLOR "\033[0m" ///< this line allows you to recolor the color of subsequent characters in the console to defoult сcolor


static const double Epsilon = 1e-5;      ///< the constant of the minimum difference at which doubles are considered different

static const int INFINITE_ROOTS = -1;    ///< a constant denoting that the equation has an infinite number of solutions

static const int OFFSER_ROOTS = 3;       ///< the amount of data up to the first root in the array with test information

struct QE_coeff
{
    double a;
    double b;
    double c;
};

struct QE_roots
{
    int count_roots;

    double x1;
    double x2;
};

///
/**
* @param [in] argc number of command line arguments
* @param [in] argv array of command line arguments
*
* Если один из флагов командной строки -d , то true, иначе false
*
* @return If one of the command line flags is -d , then true otherwise fals.
*/
bool check_flag_test(int argc, char *argv[]);

/// Function called for code testing
/**
* This function is called when you specify the start of the program -d .\n
* It contains a set of tests and checks the operation of the main program on them using the testqe() function.\n
* Also, this function outputs information about the passed tests and the result of the check to the console.\n\n
*
* Данная функция вызывается при указании запуска программы -d .\n
* Она содержит набор тестов и проверяет на них работу основной программы с помощью функции testqe().\n
* Так же эта функция выводит в консоль информацию о пройденных тестах и результат проверки.
*/
void unit_test();

/// A function that tests the operation of a test with certain parameters
/**
* @param [in] coeff coefficients of the quadratic equation
* @param [in] corr_roots correct roots of the quadratic equation
*
* @param [out] test_roots the found roots of the quadratic equation
*
* This function does not contain sets of tests, but only calls the main testing function on predefined input and output data.\n\n
*
* Эта функция не содержит набот тестов, а только вызывает функцию основного
* тестирования на заранее определённых входных и выходных данных.\n
* В случае если верный ответ совподает с выводом программы возврощается true иначе false.
*
* @return If the correct answer coincides with the output of the program, true is returned otherwise false.
*/
bool testqe(const QE_coeff coeff, const QE_roots corr_roots, QE_roots *test_roots);

/// A function that outputs the found roots of the quadratic equation
/**
* @param [out] roots roots of the quadratic equation
*
* In this function, all cases are considered separately: there are no roots, 1 root, 2 roots, infinity of roots.\n\n
*
* В этой функции отдельно рассматриваются все случаи: корней нет, 1 корень, 2 корня, бесконечность корней.
*/
void output_roots(const QE_roots roots);

/// Function for clearing the input buffer
/**
* This function clears the input buffer before moving to the next line.\n\n
*
* Эта функция очищает буфер ввода до перехода на следующую строку.
*/
void clear_buffer();

/// Function used to take equation parameters from the console
/**
* @param [in] coeff pointer to the coefficients of the quadratic equation
*
* @param [out] coeff coefficients of the quadratic equation
*
* The input will continue until the letter f is entered or 3 parameters are specified that can be written to double.\n\n
*
* В случае если введена буква f будет считаться что человек хочет завершить работу и функция вернёт true как знак того.\n
* Ввод будет продолжаться до тех пор пока не будет введена буква f или не будет указано 3 параметра которые можно записать в double.
*
* @return true if the letter f is entered, otherwise false
*/
bool input_param(QE_coeff *coeff);

/// Function for comparing 2 numbers of type double
/**
* @param [in] a the first double number
* @param [in] b the second double number
*
* A constant is used for comparison, if the difference between the stored double values differs by less than this constant,
* these numbers are considered equal.\n\n
*
* Для сравнения используется константа, если разница между сохраннёными значениями double отличается меньше чем на эту константу,
* эти числа считаются равными.\n
* Если числа равны вернётся true иначе false.
*
* @return true if the numbers are equal, otherwise false
*/
bool equal_double(double a, double b);

/// The function of solving a linear equation
/**
* @param [in] coeff coefficients of the quadratic equation
*
* @param [out] roots roots of the linear equation
*
* This function considers the linear case of a quadratic equation when the parameter a is 0, which is equivalent to a linear equation.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a равен 0, что эквивалентно линейному уравнению.
*/
void linear_equation(const QE_coeff coeff, QE_roots *roots);

/// The function of solving the correct quadratic equation
/**
* @param [in] coeff coefficients of the quadratic equation
*
* @param [out] roots roots of the quadratic equation
*
* This function considers the linear case of a quadratic equation when the parameter a is not equal to 0, which guarantees a non-infinite number of roots.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a не равен 0,
* что гарантирует не бесконечное число корней.
*/
void quadratic_equation(const QE_coeff coeff, QE_roots *roots);

/// The function of solving the quadratic equation
/**
* @param [in] coeff coefficients of the quadratic equation
*
* @param [out] roots roots of the quadratic equation
*
* This function divides the quadratic equation into 2 cases.\n
* If a is 0, then the equation is treated as linear.\n
* If a is not equal to 0, then the equation is considered as a square equation that cannot have an infinite number of roots.\n\n
*
* Эта функция разделяет квадратное уравнение на 2 случая.\n
* Если a равен 0, то уравнение рассматривается как линейное.\n
* Если а не равен 0, то уравнение рассматривается как квадратное у которого не может возникнуть бесконечное колличество корней.
*/
void solveqe(const QE_coeff coeff, QE_roots *roots);

/// A function that swaps two numbers of the double type
/**
* @param [in] a pointer to a double number
* @param [in] b pointer to a double number
*
* @param [out] a a double number
* @param [out] b a double number
*
* This function swaps 2 double numbers.\n\n
*
* Эта функция меняет местами 2 числа типа double.
*/
void swap_double(double* a, double* b);

/// Function for checking the test with the output of information to the console
/**
* @param [in] num_of_test number of test
* @param [in] coeff coefficients of the quadratic equation
* @param [in] corr_roots correct roots of the quadratic equation
*
* @param [out] count_false_test invalid test counter
*
* This function tests the program on certain data and outputs information
* to the console about whether the test was successfully passed and about the test.\n\n
*
* Эта функция тестирует программу на определённых данных и выводит в консоль
* информацию о том успешно ли пройден тест и о сомом тесте. 
*/
void print_tests_res(int num_of_test, const QE_coeff coeff, const QE_roots corr_roots, int* count_false_test);

/// This function calls the user interface in the console
void start_solve();