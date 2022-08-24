/** 
* \file unit_test.cpp 
* \brief unit test code file
*/

// void A_constructor(struct* A)
// {}

#include "quadratic_equation.h"

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
                            {9,  -6, 1,  1.0/3, 1},     // 1
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

    for (int i = 0; i < N; i++)
    {
        double a = tests[i][0], b = tests[i][1], c = tests[i][2];
        int count_roots = test_n_roots[i];
        double ans[2] = {tests[i][3], tests[i][4]};

        outputs_with_test(a, b, c, &count_roots, ans);
        
    }

    if (count_false_test == 0) 
    {
        printf(GREEN "all test accepted\n" END_COLOR);
    }
    else
    {
        printf(RED "decline %d test\n" END_COLOR, count_false_test);
    }
}

void outputs_with_test(double a, double b, double c, int* count_roots, double* ans){
    if (testqe(a, b, c, count_roots, ans))
    {
        printf(RED "error in test number %d || ", i + 1);
        count_false_test++;
    }
    else
    {
        printf(GREEN "test number %-3d accept || ", i + 1);
    }

    printf("a = %lg b = %lg c = %lg || ", a, b, c);

    if (test_n_roots[i] == Infinite_roots)
    {
        printf("true answer: count_roots = infinite || ");
    }
    else
    {
        printf("true answer: count_roots = %d ", test_n_roots[i]);

        for (int num_of_roots = 0; num_of_roots < test_n_roots[i]; num_of_roots++)
        {
            printf("x%d = %lg ", num_of_roots, tests[i][offset_root + num_of_roots]);
        }

        printf("|| ");
    }

    if (*count_roots == Infinite_roots)
    {
        printf("program answer: count_roots = infinit ");
    }
    else
    {
        printf("program answer: count_roots = %d ", *count_roots);
        for (int j = 0; j < *count_roots; j++)
        {
            printf("x%d = %lg ", j, ans[j]);
        }
    }
    printf(END_COLOR "\n");
}

bool testqe(double a, double b, double c, int* count_root, double* ans)
{
    int solveqe_count_root = 0;
    double solveqe_ans[2] = {0};

    solveqe(a, b, c, &solveqe_count_root, solveqe_ans);

    if (solveqe_count_root != *count_root || !equal_double(solveqe_ans[0], ans[0]) || !equal_double(solveqe_ans[1], ans[1]))
    {
        return true;
    }

    return false;
}
