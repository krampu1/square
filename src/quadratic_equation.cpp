/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "../include/quadratic_equation.h"
#include "../include/io.h"
#include <math.h>
#include <assert.h>
#include <string.h>

#define assert_solve assert(coeffs != NULL);     \
                     assert(solution != NULL);   \
                                                 \
                     assert(isfinite(coeffs->a));\
                     assert(isfinite(coeffs->b));\
                     assert(isfinite(coeffs->c));

static bool is_equal(double a, double b);

static bool is_zero(double a);

void clamp_zero_double(double *a);

static void sort_ascending(double *a, double *b);

void solve_linear(const Quadratic_coeffs *coeffs, Quadratic_solution *solution);

void solve_nonzero_quadratic(const Quadratic_coeffs *coeffs, Quadratic_solution *solution);

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

void solve_linear(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve

    if (is_zero(coeffs->b)) 
    {
        if (is_zero(coeffs->c))
        {
            solution->count_roots = INFINITY_ROOTS; 
        }
        else
        {
            solution->count_roots = ZERO;
        }
    }
    else
    {
        solution->count_roots = ONE;
        solution->x1 = -coeffs->c / coeffs->b;

        clamp_zero_double(&solution->x1);
    }
}

void solve_nonzero_quadratic(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve

    assert(!is_zero(coeffs->a));

    double discriminant = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

    if (is_zero(discriminant))
    {
        solution->count_roots = ONE;
        solution->x1 = -coeffs->b / (2 * coeffs->a);

        clamp_zero_double(&solution->x1);
    }
    else if (discriminant < 0)
    {
        solution->count_roots = ZERO;
    }
    else
    {
        double sqrt_discriminant = sqrt(discriminant);

        solution->count_roots = TWO;
        solution->x1 = (-coeffs->b + sqrt_discriminant) / (2 * coeffs->a);
        solution->x2 = (-coeffs->b - sqrt_discriminant) / (2 * coeffs->a);

        sort_ascending(&solution->x1, &solution->x2);

        clamp_zero_double(&solution->x1);
        clamp_zero_double(&solution->x2);
    }
}

void solve(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve

    if (is_zero(coeffs->a))
    {
        solve_linear(coeffs, solution);
    }
    else
    {
        solve_nonzero_quadratic(coeffs, solution);
    }
}