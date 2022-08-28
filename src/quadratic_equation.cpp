/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "../include/quadratic_equation.h"
#include "../include/io.h"
#include <math.h>
#include <assert.h>
#include <string.h>

void fix_zero_double(double *a);
void arrange_double(double *a, double *b);

void fix_zero_double(double *a)
{
    assert(a != NULL);
    assert(isfinite(*a));

    if (is_equal_double(*a, 0))
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

    if (*a > *b)
    {
        swap_double(a, b);
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
    int ch;
    while ((ch=getchar()) != '\n' && ch != EOF) { }
}

bool is_equal_double(double a, double b)
{
    const double Epsilon = 1e-5; 
    
    return (fabs(a-b) < Epsilon);
}

void solve_linear(const QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    if (is_equal_double(coeffs->b, 0))
    {
        if (is_equal_double(coeffs->c, 0))
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
        roots->x1 = -coeffs->c / coeffs->b;

        fix_zero_double(&roots->x1);
    }
}

void solve_quadratic(const QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    assert(!is_equal_double(coeffs->a, 0));

    double discrimenant = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

    if (is_equal_double(discrimenant, 0))
    {
        roots->count_roots = 1;
        roots->x1 = -coeffs->b / (2 * coeffs->a);

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
        roots->x1 = (-coeffs->b + sqrt_discrimenant) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b - sqrt_discrimenant) / (2 * coeffs->a);

        arrange_double(&roots->x1, &roots->x2);

        fix_zero_double(&roots->x1);
        fix_zero_double(&roots->x2);
    }
}


void solve_quadratic_equation(const QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    if (is_equal_double(coeffs->a, 0))
    {
        solve_linear(coeffs, roots);
    }
    else
    {
        solve_quadratic(coeffs, roots);
    }
}