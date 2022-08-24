#include "quadratic_equation.h"

/*! 
* \file unit_test.cpp 
* \brief unit_test file
*/

void unit_test()
{
    const int N = 10;
    double tests [N][5] = {{0, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0},
                            {3, 7, -6, -3, 2.0/3},
                            {-1, 7, 8, -1, 8},
                            {4, 4, 1, -0.5, 0},
                            {2, 1, 1, 0, 0},
                            {-1, 2, 8, -2, 4},
                            {9, -6, 1, 1.0/3, 1},
                            {1, 3, 2, -2, -1},
                            {1, -5, 6, 2, 3}};
    
    int test_n_roots[N] = {Infinite_roots, 1, 2, 2, 1, 0, 2, 1, 2, 2};

    int count_false_test = 0;
    for (int i = 0; i < N; i++)
    {
        double a = tests[i][0], b = tests[i][1], c = tests[i][2];
        int count_roots = test_n_roots[i];
        double ans[2] = {tests[i][3], tests[i][4]};
        if (testqe(a, b, c, &count_roots, ans))
        {
            printf(RED "error in test namber %d || ", i + 1);
            count_false_test++;
        }
        else
        {
            printf(GREEN "test namber %-3d accept || ", i + 1);
        }

        printf("a = %lg b = %lg c = %lg || ", a, b, c);

        if (test_n_roots[i] == Infinite_roots)
        {
            printf("true answer: count_roots = infinite || ");
        }
        else
        {
            printf("true answer: count_roots = %d ", test_n_roots[i]);
            for (int j = 0; j < test_n_roots[i]; j++)
            {
                printf("x%d = %lg ", j, tests[i][3+j]);
            }
            printf("|| ");
        }
        if (count_roots == Infinite_roots)
        {
            printf("program answer: count_roots = infinit ");
        }
        else{
            printf("program answer: count_roots = %d ", count_roots);
            for (int j = 0; j < count_roots; j++)
            {
                printf("x%d = %lg ", j, ans[j]);
            }
        }
        printf(END_COLOR "\n");
    }
    if (count_false_test == 0){
        printf(GREEN "all test accepted\n" END_COLOR);
    }
    else{
        printf(RED "decline %d test\n" END_COLOR, count_false_test);
    }
}

bool testqe(double a, double b, double c, int* count_root, double* ans)
{
    int old_count_root = *count_root;
    double old_ans[2] = {ans[0], ans[1]};

    solveqe(a, b, c, count_root, ans);

    if (old_count_root != *count_root || !equal_double(old_ans[0], ans[0]) || !equal_double(old_ans[1], ans[1])){
        return true;
    }
    return false;
}
