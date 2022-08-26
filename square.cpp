/** 
* \file square.cpp 
* \brief main code file
*/

#include <stdio.h>
#include "quadratic_equation.h"
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    if (check_flag_test(argc, argv))
    {
        unit_test();
    }
    else
    { 
        start_solve();
    }
}