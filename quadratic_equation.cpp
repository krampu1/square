/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "quadratic_equation.h"
#include <math.h>
#include <assert.h>
#include <string.h>

bool check_flag_test(int argc, char *argv[])
{
    const int STRING_FLAG_SIZE = 3;

    for (int i = 0; i < argc; i++)
    {
        if (!strncmp("-d", argv[i], STRING_FLAG_SIZE))
        {
            return true;
        }
    }

    return false;
}

void fix_zero_double(double *a)
{
    assert(a != NULL);
    assert(isfinite(*a));

    if (equal_double(*a, 0))
    {
        *a = 0;
    }  
}

void arrange_double(double *a, double *b)
{
    assert(a != NULL);
    assert(b != NULL);

    assert(isfinite(*a));
    assert(isfinite(*b));

    if (*a > * b)
    {
        double x = *a;
        *a = *b;
        *b = x;
    }
}

void start_solve()
{
    printf("this program solve quadratic equation. Press f to exit program\n");

    QE_coeff coeff = {};

    while (true)
    {
        bool exit_program = input_param(&coeff);

        if (exit_program) 
        {
            break;
        }

        QE_roots roots = {};

        solveqe(coeff, &roots);
        output_roots(roots);
    }
}

void swap_double(double* a, double* b)
{
    assert(a != NULL);
    assert(b != NULL);
    
    assert(isfinite(*a));
    assert(isfinite(*b));

    double x = *a;
    *a = *b;
    *b = x;
}

void clear_buffer()
{
    while (getchar() != '\n') { }
}

bool equal_double(double a, double b)
{
    return (fabs(a-b) < Epsilon);
}

void linear_equation(const QE_coeff coeff, QE_roots *roots)
{
    assert(roots  != NULL);

    assert(isfinite(coeff.a));
    assert(isfinite(coeff.b));
    assert(isfinite(coeff.c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    if (equal_double(coeff.b, 0))
    {
        if (equal_double(coeff.c, 0))
        {
            roots->count_roots = INFINITE_ROOTS; 
        }
        else
        {
            roots->count_roots = 0;
        }
    }
    else
    {
        roots->count_roots = 1;
        roots->x1 = -coeff.c / coeff.b;
        
        fix_zero_double(&roots->x1);
    }
}

void quadratic_equation(const QE_coeff coeff, QE_roots *roots)
{
    assert(roots != NULL);

    assert(isfinite(coeff.a));
    assert(isfinite(coeff.b));
    assert(isfinite(coeff.c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    assert(!equal_double(coeff.a, 0));

    double discrimenant = coeff.b * coeff.b - 4 * coeff.a * coeff.c;

    if (equal_double(discrimenant, 0))
    {
        roots->count_roots = 1;
        roots->x1 = -coeff.b / (2 * coeff.a);

        fix_zero_double(&roots->x1);
    }
    else if (discrimenant < 0)
    {
        roots->count_roots = 0;
    }
    else
    {
        double sqrt_discrimenant = sqrt(discrimenant);

        roots->count_roots = 2;
        roots->x1 = (-coeff.b + sqrt_discrimenant) / (2 * coeff.a);
        roots->x2 = (-coeff.b - sqrt_discrimenant) / (2 * coeff.a);

        arrange_double(&roots->x1, &roots->x2);

        fix_zero_double(&roots->x1);
        fix_zero_double(&roots->x2);
    }
}



void solveqe(const QE_coeff coeff, QE_roots *roots)
{
    assert(roots != NULL);

    assert(isfinite(coeff.a));
    assert(isfinite(coeff.b));
    assert(isfinite(coeff.c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    if (equal_double(coeff.a, 0))
    {
        linear_equation(coeff, roots);
    }
    else
    {
        quadratic_equation(coeff, roots);
    }
}