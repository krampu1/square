/** 
* \file unit_test.cpp 
* \brief unit test code file
*/

#include "../include/quadratic_equation.h"
#include "unit_test.h"

const char *TEST_FILE_PATH = "./test/tests.txt";

enum Read_const
{
    READED_SUCCESS  = 0,
    READED_END_FILE = 1,
};

enum Test_const
{
    CORRECT_TEST = 0,
    FAIL_TEST    = 1,
};

void output_answer(const QE_roots *roots, const char *str);

int read_test(FILE *input_file, QE_coeffs *coeffs, QE_roots *roots)
{
    assert(coeffs != NULL);
    assert(roots != NULL);

    assert(input_file != NULL);

    const int COUNT_READ_PARAM = 6;

    int ret_input = fscanf(input_file, "%lf %lf %lf %d %lf %lf",
                           &coeffs->a, &coeffs->b, &coeffs->c, &roots->count_roots, &roots->x1, &roots->x2);

    if (ret_input == EOF)
    {
        return READED_END_FILE;
    }

    assert(ret_input == COUNT_READ_PARAM);

    return READED_SUCCESS;
}

void unit_test()
{
    FILE *input_file = fopen(TEST_FILE_PATH, "r");

    assert(input_file != NULL);

    int count_false_test = 0;
    int num_test = 0;

    while (true)
    {
        QE_coeffs coeffs = {0, 0, 0};
        QE_roots roots = {0, 0, 0};

        int ret_read = read_test(input_file, &coeffs, &roots);

        if (ret_read == READED_END_FILE)
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

void output_answer(const QE_roots *roots, const char *str)
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

void print_tests_res(int num_of_test, const QE_coeffs *coeffs, const QE_roots *corr_roots, int *count_false_test)
{
    assert(coeffs != NULL);
    assert(coeffs != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));
    assert(isfinite(corr_roots->x1));
    assert(isfinite(corr_roots->x2));

    assert(count_false_test != NULL);

    QE_roots test_roots = {0, 0, 0};
    
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

int testqe(const QE_coeffs *coeffs, const QE_roots *corr_roots, QE_roots *test_roots)
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
    
    solve_quadratic_equation(coeffs, test_roots);

    if (corr_roots->count_roots != test_roots->count_roots
        || !equal_double(corr_roots->x1, test_roots->x1)
        || !equal_double(corr_roots->x2, test_roots->x2))
    {
        return FAIL_TEST;
    }

    return CORRECT_TEST;
}
