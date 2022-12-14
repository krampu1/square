/** 
* \file square.cpp 
* \brief main source file
*/

#ifndef TEST

#include "include\io.h"
#include <assert.h>
#include <math.h>

#else

#include "test\unit_test.h"

#endif

#include "include\quadratic_equation.h"
#include <stdio.h>

#ifndef TEST

static void greetings();

static void bye();

static void solve_out_in_consol(const Quadratic_coeffs *coeffs);

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
        if(convert_args_to_coeffs(argc, argv, &coeffs) == CONVERT_ERROR)
        {
            printf("Error about taking parameters from flags. the flag should look like -s a b c");
            return CONVERT_ERROR;
        }
        
        solve_out_in_consol(&coeffs);
    }
    else
    {
        greetings();

        while (true)
        {
            if (input_coeffs(&coeffs) == INPUT_CLOSE_FLAG) 
                break;
 
            solve_out_in_consol(&coeffs);
        }

        bye();
    }
}

#endif


#ifndef TEST

static void solve_out_in_consol(const Quadratic_coeffs *coeffs)
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