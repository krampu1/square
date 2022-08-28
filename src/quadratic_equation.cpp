/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "../include/quadratic_equation.h"
#include "../include/io.h"
#include <math.h>
#include <assert.h>
#include <string.h>

#define assert_solve assert(coeffs != NULL);assert(roots != NULL);assert(isfinite(coeffs->a));assert(isfinite(coeffs->b));assert(isfinite(coeffs->c));

static void clamp_zero_double(double *a);
static void sort_ascending(double *a, double *b);
static bool is_equal(double a, double b);
static bool is_zero(double a);

void clamp_zero_double(double *a)
{
    assert(a != NULL);
    assert(*a != NAN);

    if (is_zero(*a))
    {
        *a = 0;
    }  
}

static void sort_ascending(double *a, double *b)
{
    assert(a != NULL);
    assert(b != NULL);

    assert(*a != NAN);
    assert(*b != NAN);

    if (*a > *b)
    {
        double temp = *a;
        *a = *b;
        *b = temp;
    }
}

static bool is_equal(double a, double b)
{
    assert(isfinite(a));
    assert(isfinite(b));

    const double EPSILON = 1e-5; 
    
    return (fabs(a-b) < EPSILON);
}

static bool is_zero(double a)
{
    assert(a != NAN);

    if (is_equal(a, 0))
    {
        return true;
    }
    return false;
}

void solve_linear(const Quadratic_coeffs *coeffs, Quadratic_solution *roots)
{
    assert_solve

    if (is_zero(coeffs->b)) 
    {
        if (is_zero(coeffs->c))
        {
            roots->count_roots = INFINITE_ROOTS; 
        }
        else
        {
            roots->count_roots = ZERO;
        }
    }
    else
    {
        roots->count_roots = ONE;
        roots->x1 = -coeffs->c / coeffs->b;

        clamp_zero_double(&roots->x1);
    }
}

void solve_nonzero_quadratic(const Quadratic_coeffs *coeffs, Quadratic_solution *roots)
{
    assert_solve

    assert(!is_zero(coeffs->a));

    double discrimenant = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

    if (is_zero(discrimenant))
    {
        roots->count_roots = ONE;
        roots->x1 = -coeffs->b / (2 * coeffs->a);

        clamp_zero_double(&roots->x1);
    }
    else if (discrimenant < 0)
    {
        roots->count_roots = ZERO;
    }
    else
    {
        double sqrt_discrimenant = sqrt(discrimenant);

        roots->count_roots = TWO;
        roots->x1 = (-coeffs->b + sqrt_discrimenant) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b - sqrt_discrimenant) / (2 * coeffs->a);

        sort_ascending(&roots->x1, &roots->x2);

        clamp_zero_double(&roots->x1);
        clamp_zero_double(&roots->x2);
    }
}

void solve(const Quadratic_coeffs *coeffs, Quadratic_solution *roots)
{
    assert_solve

    if (is_zero(coeffs->a))
    {
        solve_linear(coeffs, roots);
    }
    else
    {
        solve_nonzero_quadratic(coeffs, roots);
    }
}