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

struct QE_coeffs
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
bool is_debug(int argc, char *argv[]);

/// Function for clearing the input buffer
/**
* This function clears the input buffer before moving to the next line.\n\n
*
* Эта функция очищает буфер ввода до перехода на следующую строку.
*/
void clear_buffer();

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
* @param [in] coeffs coeffsicients of the quadratic equation
*
* @param [out] roots roots of the linear equation
*
* This function considers the linear case of a quadratic equation when the parameter a is 0, which is equivalent to a linear equation.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a равен 0, что эквивалентно линейному уравнению.
*/
void linear_equation(const QE_coeffs *coeffs, QE_roots *roots);

/// The function of solving the correct quadratic equation
/**
* @param [in] coeffs coeffsicients of the quadratic equation
*
* @param [out] roots roots of the quadratic equation
*
* This function considers the linear case of a quadratic equation when the parameter a is not equal to 0, which guarantees a non-infinite number of roots.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a не равен 0,
* что гарантирует не бесконечное число корней.
*/
void quadratic_equation(const QE_coeffs *coeffs, QE_roots *roots);

/// The function of solving the quadratic equation
/**
* @param [in] coeffs coeffsicients of the quadratic equation
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
void solve_quadratic_equation(const QE_coeffs *coeffs, QE_roots *roots);

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

/// This function calls the user interface in the console
void start_solve();