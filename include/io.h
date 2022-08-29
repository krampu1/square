/** 
* \file input_output.h
* \brief input/output header file
*/

#ifndef IO
#define IO

#include "quadratic_equation.h"

enum Input_const
{
    INPUT_SUCCESS    = 0,
    INPUT_CLOSE_FLAG = 1,
};

enum Convert_const
{
    CONVERT_SUCCESS  = 0,
    CONVERT_ERROR    = 1,
    COUNT_ARG_COEFFS = 3,
};

/// Function is used to take equation parameters from the console
/**
* @param [in]  coeffs pointer to the coefficients of the quadratic equation
*
* @param [out] coeffs coefficients of the quadratic equation
*
* The input will continue until the letter 'f' is entered or 3 parameters are specified that can be written to double.\n\n
*
* 
* Ввод будет продолжаться до тех пор пока не будет введена буква 'f' или не будет указано 3 параметра которые можно записать в double.\n
*
* Возвращаемое значение: в случае если введена буква 'f' или встречено EOF, то вернётся INPUT_CLOSE_FLAG, и INPUT_SUCCESS в противном случае.
*
* @return if the letter 'f' is entered or EOF is encountered, then INPUT_CLOSE_FLAG, and INPUT_SUCCESS will be returned otherwise.
*/
int input_coeffs(Quadratic_coeffs *coeffs);

/// A function that outputs the evaluated solution of the quadratic equation
/**
* @param [out] solution solution of the quadratic equation
*
* In this function, all cases are considered separately: there are no roots, 1 root, 2 roots, infinity number of roots.\n\n
*
* В этой функции отдельно рассматриваются все случаи: корней нет, 1 корень, 2 корня, бесконечное количество корней.
*/
void output_solution(const Quadratic_solution *solution);

bool is_console_solve(const int argc, const char *argv[]);

Convert_const convert_args_to_coeffs(const int argc, const char *argv[], Quadratic_coeffs *coeffs);

#endif