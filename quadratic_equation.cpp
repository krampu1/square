/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "quadratic_equation.h"

void swap_double(double* a, double* b)
{
    if (*a > *b)
    {
        double x = *a;
        *a = *b;
        *b = x;
    }
}

void output_roots(int count_root, double* ans)
{
    if (count_root == Infinite_roots)
    {
        printf("infinit namber of roots");
    }
    else if (count_root == 0)
    {
        printf("no roots");
    }
    else
    {
        printf("namber of roots %d\n", count_root);
    }

    for (int i = 0; i < count_root; i++)
    {
        printf("%lg ", ans[i]);
    }
    printf("\n");
}

bool input_3_argument(double *a, double *b, double *c)
{
    while (true)
    {
        int accept = scanf("%lf %lf %lf", a, b, c);

        char first_char = getchar();

        if (first_char == 'f')
        {
            return true;
        }

        if (first_char != '\n'){
            while (getchar() != '\n') ;
        }

        if (accept == 3) break;

        printf("error in input data, enter 3 numbers\n");
    }
    return false;
}

bool equal_double(double a, double b)
{
    return (fabs(a-b) < Epsilon);
}

void liner_equation(double a, double b, int* count_root, double* ans)
{
    if (equal_double(a, 0))
    {
        if (equal_double(b, 0))
        {
            *count_root = Infinite_roots;
        }
        else
        {
            *count_root = 0;
        }
    }
    else
    {
        *count_root = 1;
        ans[0] = -b / a;
        
        if (equal_double(ans[0], 0))
            ans[0] = 0;
    }
}

void quadratic_equation(double a, double b, double c, int* count_root, double* ans)
{
    assert(!equal_double(a, 0));
    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        *count_root = 0;
    }
    else if (equal_double(d, 0))
    {
        *count_root = 1;
        ans[0] = -b / (2 * a);

        if (equal_double(ans[0], 0))
            ans[0] = 0;
    }
    else
    {
        double sd = sqrt(d);
        *count_root = 2;
        ans[0] = (-b + sd) / (2 * a);
        ans[1] = (-b - sd) / (2 * a);

        if (ans[0] > ans[1])
            swap_double(&ans[0], &ans[1]);

        if (equal_double(ans[0], 0))
            ans[0] = 0;
        if (equal_double(ans[1], 0))
            ans[1] = 0;
    }
}



void solveqe(double a, double b, double c, int* count_root, double* ans)
{

    if (equal_double(a, 0))
        liner_equation(b, c, count_root, ans);
    else
        quadratic_equation(a, b, c, count_root, ans);
}