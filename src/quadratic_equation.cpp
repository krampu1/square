/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation source file
*/

#include "../include/quadratic_equation.h"
#include "../include/io.h"
#include "../include/common.h"
#include <math.h>
#include <assert.h>
#include <string.h>

#define assert_solve_equation assert(coeffs   != NULL);   \
                              assert(solution != NULL);   \
                                                          \
                              assert(isfinite(coeffs->a));\
                              assert(isfinite(coeffs->b));\
                              assert(isfinite(coeffs->c));

static void solve_linear(const Quadratic_coeffs *coeffs, Quadratic_solution *solution);

static void solve_nonzero_quadratic(const Quadratic_coeffs *coeffs, Quadratic_solution *solution);

void solve(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve_equation

    if (is_zero(coeffs->a))
    {
        solve_linear(coeffs, solution);
    }
    else
    {
        solve_nonzero_quadratic(coeffs, solution);
    }
}

static void solve_linear(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve_equation

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

static void solve_nonzero_quadratic(const Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert_solve_equation

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