/** 
* \file common.cpp 
* \brief common source file
*/

#include "../include/common.h"
#include <assert.h>
#include <math.h>

void sort_ascending(double *a, double *b)
{
    assert(a != NULL);
    assert(b != NULL);

    assert(*a != NAN);
    assert(*b != NAN);

    if (*a > *b)
    {
        double temp = *a;
        *a = *b;
        *b = temp;
    }
}

void clamp_zero_double(double *a)
{
    assert(a != NULL);

    assert(*a != NAN);

    if (is_zero(*a))
    {
        *a = 0;
    }  
}

bool is_zero(double a)
{
    assert(a != NAN);

    if (is_equal(a, 0))
    {
        return true;
    }

    return false;
}

bool is_equal(double a, double b)
{
    assert(isfinite(a));
    assert(isfinite(b));

    const double EPSILON = 1e-5; 
    
    return (fabs(a-b) < EPSILON);
}