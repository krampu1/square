/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "../include/quadratic_equation.h"
#include "../include/input_output.h"
#include <math.h>
#include <assert.h>
#include <string.h>

void fix_zero_double(double *a);
void arrange_double(double *a, double *b);

bool is_debug(int argc, char *argv[])
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

    if (*a > *b)
    {
        swap_double(a, b);
    }
}

void start_solve()
{
    printf("this program solve quadratic equation. Press f to exit program\n");

    QE_coeffs coeffs = {0, 0, 0};

    while (true)
    {
        int ret_input = input_param(&coeffs);

        if (ret_input == CLOSE) 
        {
            break;
        }

        QE_roots roots = {};

        solve_quadratic_equation(&coeffs, &roots);
        output_roots(&roots);
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

void linear_equation(const QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    if (equal_double(coeffs->b, 0))
    {
        if (equal_double(coeffs->c, 0))
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

void quadratic_equation(const QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    assert(!equal_double(coeffs->a, 0));

    double discrimenant = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

    if (equal_double(discrimenant, 0))
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

    if (equal_double(coeffs->a, 0))
    {
        linear_equation(coeffs, roots);
    }
    else
    {
        quadratic_equation(coeffs, roots);
    }
}