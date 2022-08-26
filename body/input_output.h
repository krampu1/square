/** 
* \file input_output.h
* \brief input/output header file
*/

enum Input_const
{
    SUCCESS = 0,

    CLOSE   = 1,
};

/// Function used to take equation parameters from the console
/**
* @param [in] coeffs pointer to the coeffsicients of the quadratic equation
*
* @param [out] coeffs coeffsicients of the quadratic equation
*
* The input will continue until the letter f is entered or 3 parameters are specified that can be written to double.\n\n
*
* В случае если введена буква f будет считаться что человек хочет завершить работу и функция вернёт true как знак того.\n
* Ввод будет продолжаться до тех пор пока не будет введена буква f или не будет указано 3 параметра которые можно записать в double.
*
* @return int
*/
int input_param(QE_coeffs *coeffs);

/// A function that outputs the found roots of the quadratic equation
/**
* @param [out] roots roots of the quadratic equation
*
* In this function, all cases are considered separately: there are no roots, 1 root, 2 roots, infinity of roots.\n\n
*
* В этой функции отдельно рассматриваются все случаи: корней нет, 1 корень, 2 корня, бесконечность корней.
*/
void output_roots(const QE_roots *roots);