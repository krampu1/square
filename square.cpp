/** 
* \file square.cpp 
* \brief main code file
*/

#include "include\io.h"
#include "include\quadratic_equation.h"
#include "test\unit_test.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (is_test(argc, argv))
    {
        unit_test();
    }
    else
    {
        gretings();

        QE_coeffs coeffs = {0, 0, 0};

        while (true)
        {
            int ret_input = input_param(&coeffs);

            if (ret_input == INPUT_CLOSE_FLAG) 
            {
            
                break;
            }

            QE_roots roots = {};

            solve_quadratic_equation(&coeffs, &roots);
            output_roots(&roots);
        }

        bye();
    }
}