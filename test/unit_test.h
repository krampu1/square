/** 
* \file unit_test.h
* \brief unit test header file
*/

/// Function called for code testing
/**
* This function is called when you specify the start of the program -d .\n
* It contains a set of tests and checks the operation of the main program on them using the testqe() function.\n
* Also, this function outputs information about the passed tests and the result of the check to the console.\n\n
*
* Данная функция вызывается при указании запуска программы -d .\n
* Она содержит набор тестов и проверяет на них работу основной программы с помощью функции testqe().\n
* Так же эта функция выводит в консоль информацию о пройденных тестах и результат проверки.
*/
void unit_test();

/// reading a test from a file
/**
* @param [in] input_file pointer to the file for reading
* @param [in] coeffs  pointer to a structure with parameters
* @param [in] roots pointer to a structure with roots
*
* @param [out] coeffs structure with parameters
* @param [out] roots structure with roots
*
* @return int SUCCESS=>0 END_FILE=>1
*/
int read_test(FILE *input_file, QE_coeffs *coeffs, QE_roots *roots);

/// Function for checking the test with the output of information to the console
/**
* @param [in] num_of_test number of test
* @param [in] coeffs coeffsicients of the quadratic equation
* @param [in] corr_roots correct roots of the quadratic equation
*
* @param [out] count_false_test invalid test counter
*
* This function tests the program on certain data and outputs information
* to the console about whether the test was successfully passed and about the test.\n\n
*
* Эта функция тестирует программу на определённых данных и выводит в консоль
* информацию о том успешно ли пройден тест и о сомом тесте. 
*/
void print_tests_res(int num_of_test, const QE_coeffs *coeffs, const QE_roots *corr_roots, int* count_false_test);

/// A function that tests the operation of a test with certain parameters
/**
* @param [in] coeffs coeffsicients of the quadratic equation
* @param [in] corr_roots correct roots of the quadratic equation
*
* @param [out] test_roots the found roots of the quadratic equation
*
* This function does not contain sets of tests, but only calls the main testing function on predefined input and output data.\n\n
*
* Эта функция не содержит набот тестов, а только вызывает функцию основного
* тестирования на заранее определённых входных и выходных данных.\n
* В случае если верный ответ совподает с выводом программы возврощается true иначе false.
*
* @return int CORRECT=>0 FAIL=>1
*/
int testqe(const QE_coeffs *coeffs, const QE_roots *corr_roots, QE_roots *test_roots);