/** 
* \file square.cpp 
* \brief main code file
*/

#include "include\io.h"
#include "include\quadratic_equation.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (is_test(argc, argv)) // TODO: extract tests in other main (it's a good practice, should be enforced!)
    {
        unit_test();
    }
    else
    {
        gritings();

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
    }
}