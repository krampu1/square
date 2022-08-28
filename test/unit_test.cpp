/** 
* \file unit_test.cpp 
* \brief unit test code file
*/
#include "../include/quadratic_equation.h"
#include "unit_test.h"
#include <math.h>
#include <assert.h>

#define COLOR_RED "\x1B[31m"

#define COLOR_GREEN "\x1B[32m"

#define END_COLOR "\033[0m"

const char *TEST_FILE_PATH = "./test/tests.txt";

enum Read_const
{
    READ_SUCCESS  = 0,
    READ_END_FILE = 1,
};

enum Test_const
{
    CORRECT_TEST = 0,
    FAIL_TEST    = 1,
};

static bool is_equal(double a, double b)
{
    assert(a != NAN);
    assert(b != NAN);
    
    const double Epsilon = 1e-5; 
    
    return (fabs(a-b) < Epsilon);
}

void output_answer(const Quadratic_solution *roots, const char *str);

int read_test(FILE *input_file, Quadratic_coeffs *coeffs, Quadratic_solution *roots)
{
    assert(coeffs     != NULL);
    assert(roots      != NULL);
    assert(input_file != NULL);

    const int COUNT_READ_PARAM = 6;

    int ret_input = fscanf(input_file, "%lf %lf %lf %d %lf %lf",
                           &coeffs->a, &coeffs->b, &coeffs->c, &roots->count_roots, &roots->x1, &roots->x2);

    if (ret_input == EOF)
    {
        return READ_END_FILE;
    }

    assert(ret_input == COUNT_READ_PARAM);

    return READ_SUCCESS;
}

int main()
{
    FILE *input_file = fopen(TEST_FILE_PATH, "r");
    
    assert(input_file != NULL);

    int count_false_test = 0;
    int num_test = 0;

    while (true)
    {
        Quadratic_coeffs coeffs = {0, 0, 0};
        Quadratic_solution roots = {ZERO, 0, 0};

        int ret_read = read_test(input_file, &coeffs, &roots);

        if (ret_read == READ_END_FILE)
        {
            break;
        }

        print_tests_res(num_test++, &coeffs, &roots, &count_false_test);
    }

    if (count_false_test == 0) 
    {
        printf(COLOR_GREEN "all test accepted\n" END_COLOR);
    }
    else
    {
        printf(COLOR_RED "decline %d test\n" END_COLOR, count_false_test);
    }
}

void output_answer(const Quadratic_solution *roots, const char *str)
{
    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    assert(str != NULL);

    printf("%s", str);

    if (roots->count_roots == INFINITE_ROOTS)
    {
        printf(" answer: count_roots = infinit ");
    }
    else
    {
        printf(" answer: count_roots = %d x1 = %lg x2 = %lg", roots->count_roots, roots->x1, roots->x2);
    }
}

void print_tests_res(int num_of_test, const Quadratic_coeffs *coeffs, const Quadratic_solution *corr_roots, int *count_false_test)
{
    assert(coeffs != NULL);
    assert(coeffs != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));
    assert(isfinite(corr_roots->x1));
    assert(isfinite(corr_roots->x2));

    assert(count_false_test != NULL);

    Quadratic_solution test_roots = {ZERO, 0, 0};
    
    if (testqe(coeffs, corr_roots, &test_roots) == FAIL_TEST)
    {
        printf(COLOR_RED "error in test number %d || ", num_of_test + 1);
        (*count_false_test)++;
    }
    else
    {
        printf(COLOR_GREEN "test number %-3d accept || ", num_of_test + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", coeffs->a, coeffs->b, coeffs->c);

    output_answer(corr_roots, "true");
    printf(" || ");
    output_answer(&test_roots, "program");

    printf(END_COLOR "\n");
}

int testqe(const Quadratic_coeffs *coeffs, const Quadratic_solution *corr_roots, Quadratic_solution *test_roots)
{
    assert(test_roots != NULL);
    assert(corr_roots != NULL);
    assert(coeffs != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(isfinite(corr_roots->x1));
    assert(isfinite(corr_roots->x2));

    assert(isfinite(test_roots->x1));
    assert(isfinite(test_roots->x2));
    
    solve(coeffs, test_roots);

    if (corr_roots->count_roots != test_roots->count_roots
        || !is_equal(corr_roots->x1, test_roots->x1)
        || !is_equal(corr_roots->x2, test_roots->x2))
    {
        return FAIL_TEST;
    }

    return CORRECT_TEST;
}
