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

#define assert_cor_test_data assert(isfinite(coeffs->a));        \
                             assert(isfinite(coeffs->b));        \
                             assert(isfinite(coeffs->c));        \
                                                                 \
                             assert(isfinite(corr_solution->x1));\
                             assert(isfinite(corr_solution->x2));

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

void output_answer(const Quadratic_solution *solution, const char *str);

static bool is_equal(double a, double b)
{
    assert(a != NAN);
    assert(b != NAN);
    
    const double EPSILON = 1e-5; 
    
    return (fabs(a-b) < EPSILON);
}

void output_answer(const Quadratic_solution *solution, const char *str)
{
    assert(solution != NULL);
    assert(str      != NULL);

    printf("%s", str);

    if (solution->count_roots == INFINITY_ROOTS)
    {
        printf(" answer: count_roots = infinity ");
    }
    else
    {
        printf(" answer: count_roots = %d x1 = %lg x2 = %lg", solution->count_roots, solution->x1, solution->x2);
    }
}

int read_test(FILE *input_file, Quadratic_coeffs *coeffs, Quadratic_solution *solution)
{
    assert(coeffs     != NULL);
    assert(solution   != NULL);
    assert(input_file != NULL);

    const int COUNT_READ_PARAM = 6;

    int ret_input = fscanf(input_file, "%lf %lf %lf %d %lf %lf",
                           &coeffs->a, &coeffs->b, &coeffs->c, &solution->count_roots, &solution->x1, &solution->x2);

    if (ret_input == EOF)
    {
        return READ_END_FILE;
    }

    assert(ret_input == COUNT_READ_PARAM);

    return READ_SUCCESS;
}

void unit_test()
{
    FILE *input_file = fopen(TEST_FILE_PATH, "r");
    
    assert(input_file != NULL);

    int count_false_test = 0;
    int num_test = 0;

    while (true)
    {
        Quadratic_coeffs coeffs = {0, 0, 0};
        Quadratic_solution solution = {ZERO, 0, 0};

        int ret_read = read_test(input_file, &coeffs, &solution);

        if (ret_read == READ_END_FILE)
        {
            break;
        }

        print_tests_res(num_test++, &coeffs, &solution, &count_false_test);
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

void print_tests_res(int num_of_test, const Quadratic_coeffs *coeffs, const Quadratic_solution *corr_solution, int *count_false_test)
{
    assert(coeffs           != NULL);
    assert(corr_solution    != NULL);
    assert(count_false_test != NULL);

    assert_cor_test_data

    Quadratic_solution test_solution = {ZERO, 0, 0};
    
    if (testqe(coeffs, corr_solution, &test_solution) == FAIL_TEST)
    {
        printf(COLOR_RED "error in test number %d || ", num_of_test + 1);
        (*count_false_test)++;
    }
    else
    {
        printf(COLOR_GREEN "test number %-3d accept || ", num_of_test + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", coeffs->a, coeffs->b, coeffs->c);

    output_answer(corr_solution, "true");
    printf(" || ");
    output_answer(&test_solution, "program");

    printf(END_COLOR "\n");
}

int testqe(const Quadratic_coeffs *coeffs, const Quadratic_solution *corr_solution, Quadratic_solution *test_solution)
{
    assert(test_solution != NULL);
    assert(corr_solution != NULL);
    assert(coeffs        != NULL);

    assert_cor_test_data

    assert(isfinite(test_solution->x1));
    assert(isfinite(test_solution->x2));
    
    solve(coeffs, test_solution);

    if (corr_solution->count_roots  !=  test_solution->count_roots
        || !is_equal(corr_solution->x1, test_solution->x1)
        || !is_equal(corr_solution->x2, test_solution->x2))
    {
        return FAIL_TEST;
    }
    
    return CORRECT_TEST;
}
