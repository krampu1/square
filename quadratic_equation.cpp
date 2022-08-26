/** 
* \file quadratic_equation.cpp 
* \brief quadratic equation code file
*/

#include "quadratic_equation.h"
#include <math.h>
#include <assert.h>
#include <string.h>

bool check_flag_test(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if (!strncmp("-d", argv[i], 3))
        {
            return true;
        }
    }

    return false;
}

void fix_zero_double(double *a)
{
    assert(a != NULL);

    assert(isfinite(*a));

    if (equal_double(*a, 0))
    {
        *a = 0;
    }  
}

void arrange_double(double *a, double *b)
{
    assert(a != NULL);
    assert(b != NULL);

    assert(isfinite(*a));
    assert(isfinite(*b));

    if (*a > * b)
    {
        double x = *a;
        *a = *b;
        *b = x;
    }
}

void start_solve()
{
    printf("this program solve quadratic equation. To exit, press f\n");

    while (true)
    {
        Equation_data data_in;

        bool exit_program = input_param(&data_in);

        if (exit_program) 
        {
            break;
        }

        Equation_data data_out;
        data_out.a = data_in.a;
        data_out.b = data_in.b;
        data_out.c = data_in.c;

        solveqe(&data_in, &data_out);
        output_roots(&data_out);
    }
}

void swap_double(double* a, double* b)
{
    assert(a != NULL);
    assert(b != NULL);
    
    assert(isfinite(*a));
    assert(isfinite(*b));

    double x = *a;
    *a = *b;
    *b = x;
}

void clear_buffer()
{
    while (getchar() != '\n') { }
}

bool equal_double(double a, double b)
{
    return (fabs(a-b) < Epsilon);
}

void linear_equation(Equation_data *data_in, Equation_data *data_out)
{
    assert(data_in  != NULL);
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

    if (equal_double(data_in->b, 0))
    {
        if (equal_double(data_in->c, 0))
        {
            data_out->count_roots = Infinite_roots; 
        }
        else
        {
            data_out->count_roots = 0;
        }
    }
    else
    {
        data_out->count_roots = 1;
        data_out->x1 = -data_in->c / data_in->b;
        
        fix_zero_double(&(data_out->x1));
    }
}

void quadratic_equation(Equation_data *data_in, Equation_data *data_out)
{
    assert(data_in  != NULL);
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

    assert(!equal_double(data_in->a, 0));

    double discrimenant = data_in->b * data_in->b - 4 * data_in->a * data_in->c;

    if (equal_double(discrimenant, 0))
    {
        data_out->count_roots = 1;
        data_out->x1 = -(data_in->b) / (2 * (data_in->a));

        fix_zero_double(&(data_out->x1));
    }
    else if (discrimenant < 0)
    {
        data_out->count_roots = 0;
    }
    else
    {
        double sqrt_discrimenant = sqrt(discrimenant);

        data_out->count_roots = 2;
        data_out->x1 = (-(data_in->b) + sqrt_discrimenant) / (2 * (data_in->a));
        data_out->x2 = (-(data_in->b) - sqrt_discrimenant) / (2 * (data_in->a));

        arrange_double(&(data_out->x1), &(data_out->x2));

        fix_zero_double(&(data_out->x1));
        fix_zero_double(&(data_out->x2));
    }
}



void solveqe(Equation_data *data_in, Equation_data *data_out)
{
    assert(data_in  != NULL);
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

    if (equal_double(data_in->a, 0))
    {
        linear_equation(data_in, data_out);
    }
    else
    {
        quadratic_equation(data_in, data_out);
    }
}