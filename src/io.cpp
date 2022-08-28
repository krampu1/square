/** 
* \file input_output.cpp 
* \brief input/output code file
*/

#include "../include/io.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

static void skip_stdin_line()
{
    int ch = 0;
    
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        continue;
    }
}

void greetings()
{
    printf("This program solves a quadratic equation. Press f to exit the program.\n");
}

void bye()
{
    printf("The program has terminated because the input has been completed.");
}

void output_roots(const Quadratic_solution *roots)
{
    assert(roots != NULL);

    printf("solution of the equation: ");

    switch (roots->count_roots)
    {
        case INFINITE_ROOTS:

            printf("infinite number of roots.\n");
            break;
        
        case ZERO:

            printf("no roots.\n");
            break;

        case ONE:
            assert(isfinite(roots->x1));
            
            printf("x1 = %lg\n", roots->x1);
            break;

        case TWO:
            assert(isfinite(roots->x1));
            assert(isfinite(roots->x2));

            printf("x1 = %lg x2 = %lg\n", roots->x1, roots->x2);
            break;

        default:

            printf("Error in switch in line %d in file %s.\n count_roots = %d\n", __LINE__, __FILE__, roots->count_roots);
            break;
    }
}

int input_coeffs(Quadratic_coeffs *coeffs)
{
    assert(coeffs != NULL);

    const int COUNT_INPUT_PARAM = 3;

    printf("Enter a, b, c:\n");

    while (true)
    {
        int num_correctly_numbers = scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);

        if (num_correctly_numbers == EOF)
        {
            return INPUT_CLOSE_FLAG;
        }

        int first_char = getchar();

        if (first_char == 'f' || first_char == EOF)
        {
            return INPUT_CLOSE_FLAG;
        }

        if (first_char != '\n') 
        {
            printf("After 3 arguments, some characters were entered.\n");
            skip_stdin_line();
        }

        if (num_correctly_numbers == COUNT_INPUT_PARAM) 
        {
            break;
        }

        printf("Error in input data, enter 3 numbers:\n");
    }

    return INPUT_SUCCESS;
}