/** 
* \file quadratic_equation.h
* \brief quadratic equation header file
*/
#ifndef QUADRATIC_EQUATION
#define QUADRATIC_EQUATION

#include <math.h>
#include <stdio.h>
#include <assert.h>

static const int INFINITE_ROOTS = -1;    ///< a constant denoting that the equation has an infinite number of solutions

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
bool is_equal_double(double a, double b);

/// The function of solving a linear equation
/**
* @param [in] coeffs coefficients of the quadratic equation
*
* @param [out] roots roots of the linear equation
*
* This function considers the linear case of a quadratic equation when the parameter a is 0, which is equivalent to a linear equation.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a равен 0, что эквивалентно линейному уравнению.
*/
void solve_linear(const QE_coeffs *coeffs, QE_roots *roots);

/// The function of solving the correct quadratic equation
/**
* @param [in] coeffs coefficients of the quadratic equation
*
* @param [out] roots roots of the quadratic equation
*
* This function considers the linear case of a quadratic equation when the parameter a is not equal to 0, which guarantees a non-infinite number of roots.\n\n
*
* Эта функция рассматривает часный случай квадратного уравнения, когда параметр a не равен 0,
* что гарантирует не бесконечное число корней.
*/
void solve_quadratic(const QE_coeffs *coeffs, QE_roots *roots);

/// The function of solving the quadratic equation
/**
* @param [in] coeffs coefficients of the quadratic equation
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
 
#endif