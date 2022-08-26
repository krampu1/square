/** 
* \file unit_test.cpp 
* \brief unit test code file
*/

#include "quadratic_equation.h"
#include <string.h>
#include <assert.h>

bool read_test(FILE *input_file, QE_coeff *coeff, QE_roots *roots)
{
    assert(coeff != NULL);
    assert(roots != NULL);

    const int COUNT_READ_PARAM = 6;

    int ret_input = fscanf(input_file, "%lf %lf %lf %d %lf %lf",
                           &coeff->a, &coeff->b, &coeff->c, &roots->count_roots, &roots->x1, &roots->x2);

    if (ret_input == EOF)
    {
        return true;
    }

    assert(ret_input == COUNT_READ_PARAM);

    return false;
}

void unit_test()
{
    
    FILE *input_file = fopen("tests.txt", "r");

    assert(input_file != NULL);

    int count_false_test = 0;
    int num_test = 0;

    while (true)
    {
        QE_coeff coeff = {};
        QE_roots roots = {};

        bool end_file = read_test(input_file, &coeff, &roots);

        if (end_file)
        {
            break;
        }

        print_tests_res(++num_test, coeff, roots, &count_false_test);
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

void output_answer(QE_roots roots, const char* str)
{
    assert(isfinite(roots.x1));
    assert(isfinite(roots.x2));

    assert(str != NULL);

    printf(str);

    if (roots.count_roots == INFINITE_ROOTS)
    {
        printf(" answer: count_roots = infinit ");
    }
    else
    {
        printf(" answer: count_roots = %d x1 = %lg x2 = %lg", roots.count_roots, roots.x1, roots.x2);
    }
}

void print_tests_res(int num_of_test, const QE_coeff coeff, const QE_roots corr_roots, int* count_false_test)
{
    assert(isfinite(coeff.a));
    assert(isfinite(coeff.b));
    assert(isfinite(coeff.c));
    assert(isfinite(corr_roots.x1));
    assert(isfinite(corr_roots.x2));

    assert(count_false_test != NULL);

    QE_roots test_roots = {};
    
    if (testqe(coeff, corr_roots, &test_roots))
    {
        printf(COLOR_RED "error in test number %d || ", num_of_test + 1);
        *count_false_test++;
    }
    else
    {
        printf(COLOR_GREEN "test number %-3d accept || ", num_of_test + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", coeff.a, coeff.b, coeff.c);

    output_answer(corr_roots, "true");

    printf(" || ");

    output_answer(test_roots, "program");

    printf(END_COLOR "\n");
}

bool testqe(const QE_coeff coeff, const QE_roots corr_roots, QE_roots *test_roots)
{
    assert(test_roots != NULL);

    assert(isfinite(coeff.a));
    assert(isfinite(coeff.b));
    assert(isfinite(coeff.c));

    assert(isfinite(corr_roots.x1));
    assert(isfinite(corr_roots.x2));

    assert(isfinite(test_roots->x1));
    assert(isfinite(test_roots->x2));
    
    solveqe(coeff, test_roots);

    if (corr_roots.count_roots != test_roots->count_roots
        || !equal_double(corr_roots.x1, test_roots->x1)
        || !equal_double(corr_roots.x2, test_roots->x2))
    {
        return true;
    }

    return false;
}
