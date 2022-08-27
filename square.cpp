/** 
* \file square.cpp 
* \brief main code file
*/

#include "include\quadratic_equation.h"
#include "test\unit_test.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (is_debug(argc, argv))
    {
        unit_test();
    }
    else
    { 
        start_solve();
    }
}