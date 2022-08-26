/** 
* \file unit_test.cpp 
* \brief unit test code file
*/

// void A_constructor(struct* A)
// {}

#include "quadratic_equation.h"
#include <string.h>
#include <assert.h>

bool input_test(FILE *input_file, Equation_data *data_in)
{
    int ret_input = fscanf(input_file, "%lf %lf %lf %d %lf %lf",
    &(data_in->a), &(data_in->b), &(data_in->c), &(data_in->count_roots), &(data_in->x1), &(data_in->x2));

    if (ret_input == EOF){
        return true;
    }
    return false;
}

void unit_test()
{
    int count_false_test = 0;

    FILE *input_file = fopen("tests.txt", "r");

    assert(input_file != NULL);

    int num_test = 0;
    while (true)
    {
        Equation_data data_in;

        bool end_file = input_test(input_file, &data_in);

        if (end_file)
        {
            break;
        }

        print_tests_res(++num_test, &data_in, &count_false_test);
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

void output_answer(Equation_data *data_out)
{
    assert(data_out != NULL);

    assert(isfinite(data_out->a));
    assert(isfinite(data_out->b));
    assert(isfinite(data_out->c));
    assert(isfinite(data_out->x1));
    assert(isfinite(data_out->x2));

    printf(" answer: count_roots = %d x1 = %lg x2 = %lg", data_out->count_roots, data_out->x1, data_out->x2);
}

void print_tests_res(int num_of_test, Equation_data *data_in, int* count_false_test)
{
    assert(data_in != NULL);

    assert(isfinite(data_in->a));
    assert(isfinite(data_in->b));
    assert(isfinite(data_in->c));
    assert(isfinite(data_in->x1));
    assert(isfinite(data_in->x2));

    assert(count_false_test != NULL);

    Equation_data data_out;
    data_out.a = data_in->a;
    data_out.b = data_in->b;
    data_out.c = data_in->c;
    
    if (testqe(data_in, &data_out))
    {
        printf(COLOR_RED "error in test number %d || ", num_of_test + 1);
        *count_false_test++;
    }
    else
    {
        printf(COLOR_GREEN "test number %-3d accept || ", num_of_test + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", data_in->a, data_in->b, data_in->c);

    if (data_in->count_roots == Infinite_roots)
    {
        printf("true answer: count_roots = infinite");
    }
    else
    {
        printf("true");
        output_answer(data_in);
    }

    printf(" || ");

    if (data_out.count_roots == Infinite_roots)
    {
        printf("program answer: count_roots = infinit ");
    }
    else
    {
        printf("program");
        output_answer(&data_out);
    }

    printf(END_COLOR "\n");
}

bool testqe(Equation_data *data_in, Equation_data *data_out)
{
    assert(data_in != NULL);
    assert(data_out != NULL);

    assert(isfinite(data_in->a));
    assert(isfinite(data_in->b));
    assert(isfinite(data_in->c));
    assert(isfinite(data_in->x1));
    assert(isfinite(data_in->x2));

    assert(isfinite(data_out->a));
    assert(isfinite(data_out->b));
    assert(isfinite(data_out->c));
    assert(isfinite(data_out->x1));
    assert(isfinite(data_out->x2));
    
    solveqe(data_in, data_out);

    if (data_in->count_roots != data_out->count_roots
        || !equal_double(data_in->x1, data_out->x1)
        || !equal_double(data_in->x2, data_out->x2))
    {
        return true;
    }

    return false;
}
