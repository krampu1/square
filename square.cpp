/** 
* \file square.cpp 
* \brief main source file
*/

#ifndef TEST

#include "include\io.h"

#endif

#include "include\quadratic_equation.h"
#include <stdio.h>

#ifdef TEST

#include "test\unit_test.h"

#endif

#ifndef TEST

static void greetings();

static void bye();

static void solve_outconsol(const Quadratic_coeffs *coeffs)

#endif

#ifdef TEST

int main()
{
    unit_test();
}

#else

int main(const int argc, const char* argv[])
{
    Quadratic_coeffs coeffs = {0, 0, 0};

    if (is_console_solve(argc, argv))
    {
        Convert_const ret_get = convert_args_to_coeffs(argc, argv, &coeffs);

        if(ret_get == CONVERT_ERROR)
        {
            printf("Error about taking parameters from flags. the flag should look like -s a b c");

            return CONVERT_ERROR;
        }
        
        solve_outconsol(&coeffs);
    }
    else
    {
        greetings();

        while (true)
        {

            int ret_input = input_coeffs(&coeffs);

            if (ret_input == INPUT_CLOSE_FLAG) 
            {
                break;
            }
            
            solve_outconsol(&coeffs);
        }

        bye();
    }
}

#endif


#ifndef TEST

static void solve_outconsol(const Quadratic_coeffs *coeffs)
{
    assert(coeffs != NULL);

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    Quadratic_solution roots = {ZERO, 0, 0};

    solve(coeffs,  &roots);
    output_solution(&roots);
}

static void greetings()
{
    printf("This program solves a quadratic equation. Press f to exit the program.\n");
}

static void bye()
{
    printf("The program has terminated because the input has been completed.");
}

#endif