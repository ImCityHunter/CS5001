/*
 * main_v2.c
 *
 * Defines main function
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

// declaration of main test function in test_all.c
extern CU_ErrorCode test_all();

/**
* Main program to invoke test functions
*
* @return the exit status of the unit tests
*/
int main(void) {

	// test all the functions
	CU_ErrorCode code = test_all();
	return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}
