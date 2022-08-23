#include <stdio.h>
#include "quadratic_equation.h"
#include <ctype.h>
#define test true

int main() 
{
#if test
    unit_test();
#else
    double a = 0, b = 0, c = 0;
    double ans[2] = {0};
    int count_root = 0;
    
    printf("this program solve quadratic equation. To exit, press f\n");
    while (true)
    {
        printf("enter a, b, c:\n");

        bool exit_program = input_3_argument(&a, &b, &c);

        if (exit_program)
        {
            break;
        }

        solveqe(a, b, c, &count_root, ans);
        output_roots(count_root, ans);
    }
#endif
    printf("by");
}