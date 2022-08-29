/** 
* \file quadratic_equation.h
* \brief quadratic equation header file
*/
#ifndef QUADRATIC_EQUATION
#define QUADRATIC_EQUATION

enum Quadratic_num_of_roots
{
    INFINITY_ROOTS = -1,
    ZERO           =  0,
    ONE            =  1,
    TWO            =  2,
};

struct Quadratic_coeffs
{
    double a;
    double b;
    double c;
};

struct Quadratic_solution
{
    Quadratic_num_of_roots count_roots;

    double x1;
    double x2;
};

/// The function of solving the quadratic equation
/**
* @param [in]  coeffs coefficients of the quadratic equation
*
* @param [out] solution solution of the quadratic equation
*
* This function divides the quadratic equation into 2 cases.\n
* If a is 0, then the equation is treated as linear.\n
* If a is not equal to 0, then the equation is considered as a square equation that cannot have an infinite number of roots.\n\n
*
* Эта функция разделяет квадратное уравнение на 2 случая.\n
* Если a равен 0, то уравнение рассматривается как линейное.\n
* Если а не равен 0, то уравнение рассматривается как квадратное у которого не может возникнуть бесконечное колличество корней.
*/
void solve(const Quadratic_coeffs *coeffs, Quadratic_solution *solution);

#endif