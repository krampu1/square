/** 
* \file quadratic_equation.h
* \brief quadratic equation header file
*/

#include <math.h>
#include <stdio.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define END_COLOR "\033[0m"

const double Epsilon = 1e-5;

const int Infinite_roots = -1;

void unit_test();

bool testqe(double a, double b, double c, int* count_root, double* ans);

void output_roots(int count_root, double* ans);

void unit_test();

bool input_3_argument(double *a, double *b, double *c);

bool equal_double(double a, double b);

void solveqe(double a, double b, double c, int* count_root, double* ans);

void swap_double(double* a, double* b);