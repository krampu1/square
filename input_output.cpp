#include "quadratic_equation.h"
#include <math.h>

void output_roots(Equation_data *data_out)
{
    assert(data_out != NULL);

    assert(isfinite(data_out->a));
    assert(isfinite(data_out->b));
    assert(isfinite(data_out->c));
    assert(isfinite(data_out->x1));
    assert(isfinite(data_out->x2));

    if (data_out->count_roots == Infinite_roots)
    {
        printf("infinit number of roots\n");
    }
    else if (data_out->count_roots == 0)
    {
        printf("no roots\n");
    }
    else
    {
        printf("number of roots %d\n", data_out->count_roots);

        if (data_out->count_roots == 1)
        {
            printf("%lg\n", data_out->x1);
        }
        else{
            printf("%lg %lg\n", data_out->x1, data_out->x2);
        }
    }
}

bool input_param(Equation_data *data_in)
{
    assert(data_in != NULL);

    printf("enter a, b, c:\n");

    while (true)
    {
        int num_correctly_numbers = scanf("%lf %lf %lf", &(data_in->a), &(data_in->b), &(data_in->c));

        if (num_correctly_numbers == EOF)
        {
            return true;
        }

        char first_char = getchar();

        if (first_char == 'f')
        {
            return true;
        }

        if (first_char != '\n') 
        {
            clear_buffer();
        }

        if (num_correctly_numbers == count_input_param) 
        {
            break;
        }

        printf("error in input data, enter 3 numbers\n");
    }

    return false;
}