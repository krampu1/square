#include "quadratic_equation.h"
#include <math.h>

void output_roots(const QE_roots roots)
{
    assert(isfinite(roots.x1));
    assert(isfinite(roots.x2));

    switch (roots.count_roots)
    {
        case INFINITE_ROOTS:

            printf("infinit number of roots\n");
            break;
        
        case 0:

            printf("no roots\n");
            break;

        case 1:

            printf("x1 = %lg\n", roots.x1);
            break;

        case 2:

            printf("x1 = %lg x2 = %lg\n", roots.x1, roots.x2);
            break;

        default:

            printf("error in switch in line %d in file %s.\n count_roots = %d\n", __LINE__, __FILE__, roots.count_roots);
            break;
    }
}

bool input_param(QE_coeff *coeff)
{
    assert(coeff != NULL);

    const int COUNT_INPUT_PARAM = 3;

    printf("enter a, b, c:\n");

    while (true)
    {
        int num_correctly_numbers = scanf("%lf %lf %lf", &coeff->a, &coeff->b, &coeff->c);

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

        if (num_correctly_numbers == COUNT_INPUT_PARAM) 
        {
            break;
        }

        printf("error in input data, enter 3 numbers\n");
    }

    return false;
}