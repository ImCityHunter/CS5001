

/**
 * @file assignment-1.c
 * @author  yu2749luca
 * @date // Sep 10, 2018
 * This is the first programming assignment for CS 5001.
 */
#include <stdbool.h>
#include <stdio.h>

/**
 * when printing byte use %u, not use %d (9/17)
 */

int main(void) {
	// YOUR CODE HERE

	//An unsigned integer constant squareOfThree initialized by calculating the square of 3
	unsigned const int squareofthree = 3*3;
	printf("variable square of three is %u and has %d Bytes\n" ,squareofthree, sizeof(squareofthree));

	//A double precision floating point constant e initialized to Euler's constant 2.718281828459045
	const double e = 2.718281828459045;
	printf("variable e is %f and has %d Bytes\n",e, sizeof(e));

	//A boolean variable isGreaterThan initialized to the logical expression 2.8 > e
	bool isGreaterThan = 2.8 > e;
	printf("variable isGreaterThan is %d and has %d Bytes\n",isGreaterThan, sizeof(isGreaterThan));

	//An integer variable quotient initialized to the ratio of sum 2+4+5 divided by 3
	int quotient = (2+4+5)/3;
	printf("variable quotient is %d and has %d Bytes\n",quotient, sizeof(quotient));

	//A local short integer variable remainder that is the remainder of 11 with 3
	short int remainder = 11%3;
	printf("variable remainder is %d and has %d Bytes\n",remainder, sizeof(remainder));

	//A double precision variable greaterValue that is 2.8 if isGreaterThan is true and e if isGreaterThan is false.
	double greaterValue = (isGreaterThan==true) ? 2.8:e;
	printf("variable greaterValue is %0.2f and has %d Bytes\n",greaterValue, sizeof(greaterValue));

	//A single precision floating point constant oneTenth initialized to the ratio of 1.0 divided by 10.0
	const float oneTenth = 1.0f/10.0f;
	printf("variable oneTenth is %.2f and has %u Bytes\n",oneTenth, sizeof(oneTenth));

	//A character whose value is the hexidecimal constant 7A
	//also work if it is = 0x74
	const char hexidecimal='\x7A';
	printf("variable hexidecimal is %c and has %d Bytes\n",hexidecimal,sizeof(hexidecimal));

	//A character constant charZ initialized to 'Z'.
	const char charZ='Z';
	printf("variable charZ is %c and has %d Bytes\n",charZ, sizeof(charZ));

	//An unsigned short variable numLetters that is the number of letters between 'A' and 'Z' inclusive.
	unsigned short numLetters = ('Z'-'A')+1;
	printf("variable numLetters is %u and has %d Bytes \n",numLetters,sizeof(numLetters));
}
