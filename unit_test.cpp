/** 
* \file unit_test.cpp 
* \brief unit test code file
*/

// void A_constructor(struct* A)
// {}

#include "quadratic_equation.h"
#include <string.h>
#include <assert.h>

bool check_test(int argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp("-d", argv[i])) return true;
    }
    return false;
}

void unit_test()
{
    const int N = 10;
    //                       a   b   c   x1     x2      num_of roots
    double tests [N][5] = { {0,  0,  0,  0,     0},     // infinite_roots
                            {0,  1,  0,  0,     0},     // 1
                            {3,  7,  -6, -3,    2.0/3}, // 2
                            {-1, 7,  8,  -1,    8},     // 2
                            {4,  4,  1,  -0.5,  0},     // 1
                            {2,  1,  1,  0,     0},     // 0
                            {-1, 2,  8,  -2,    4},     // 2
                            {9,  -6, 1,  1.0/3, 0},     // 1
                            {1,  3,  2,  -2,    -1},    // 2
                            {1,  -5, 6,  2,     3}      // 2
                          };
    
    int test_n_roots[N] = { Infinite_roots, 
                            1, 
                            2, 
                            2, 
                            1, 
                            0, 
                            2, 
                            1, 
                            2, 
                            2
                          };

    int count_false_test = 0;

    for (int i = 0; i < N; i++) print_tests_res(i, tests[i], test_n_roots[i], &count_false_test);

    if (count_false_test == 0) 
    {
        printf(COLOR_GREEN "all test accepted\n" END_COLOR);
    }
    else
    {
        printf(COLOR_RED "decline %d test\n" END_COLOR, count_false_test);
    }
}

void print_tests_res(int num_of_test, double* test, int count_root, int* count_false_test)
{
    assert(test != NULL);
    assert(count_false_test != NULL);

    double a = test[0], b = test[1], c = test[2];
    int testqe_count_roots = count_root;
    double testqe_ans[2] = { test[offset_root+0], test[offset_root+1] };

    if (testqe(a, b, c, &testqe_count_roots, testqe_ans))
    {
        printf(COLOR_RED "error in test number %d || ", num_of_test + 1);
        *count_false_test++;
    }
    else
    {
        printf(COLOR_GREEN "test number %-3d accept || ", num_of_test + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", a, b, c);

    if (count_root == Infinite_roots)
    {
        printf("true answer: count_roots = infinite || ");
    }
    else
    {
        printf("true answer: count_roots = %d ", count_root);

        for (int num_of_roots = 0; num_of_roots < count_root; num_of_roots++)
        {
            printf("x%d = %lg ", num_of_roots, test[offset_root + num_of_roots]);
        }

        printf("|| ");
    }

    if (testqe_count_roots == Infinite_roots)
    {
        printf("program answer: count_roots = infinit ");
    }
    else
    {
        printf("program answer: count_roots = %d ", testqe_count_roots);
        for (int num_of_root = 0; num_of_root < testqe_count_roots; num_of_root++)
        {
            printf("x%d = %lg ", num_of_root, testqe_ans[num_of_root]);
        }
    }

    printf(END_COLOR "\n");
}

bool testqe(double a, double b, double c, int* count_root, double* ans)
{
    assert(count_root != NULL);
    assert(ans != NULL);

    int solveqe_count_root = 0;
    double solveqe_ans[2] = {0};
    
    solveqe(a, b, c, &solveqe_count_root, solveqe_ans);

    bool equal_test = solveqe_count_root != *count_root || 
                      !equal_double(solveqe_ans[0], ans[0]) || 
                      !equal_double(solveqe_ans[1], ans[1]);
    
    ans[0] = solveqe_ans[0];
    ans[1] = solveqe_ans[1];

    if (equal_test)
    {
        return true;
    }

    return false;
}
