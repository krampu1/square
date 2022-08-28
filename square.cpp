/** 
* \file square.cpp 
* \brief main code file
*/

#include "include\io.h"
#include "include\quadratic_equation.h"
#include <stdio.h>

#include "test\unit_test.h"

int main() 
{
#ifdef TEST
    unit_test();
#endif
#ifndef TEST
    greetings();

    Quadratic_coeffs coeffs = {0, 0, 0};

    while (true)
    {
        int ret_input = input_coeffs(&coeffs);

        if (ret_input == INPUT_CLOSE_FLAG) 
        {
        
            break;
        }

        Quadratic_solution roots = {};

        solve(&coeffs, &roots);
        output_roots(&roots);
    }

    bye();
#endif
}