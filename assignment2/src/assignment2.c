

/**
 * @file assignment-2.c
 * @author  yu2749luca, HoKang Yu
 * @date // Sep 10, 2018
 * This is the second programming assignment for CS 5001.
 */
#include <stdbool.h>
#include <stdio.h>

/* @function countCalls
 * @summary increments when calls with false & return 0; return counts and reset count to 0 when calls with true
 * @param 'reset' is a boolean
 * @return return 0 if reset is false or return count if reset is true
 */
static unsigned int problem1count;
unsigned int countCalls(bool reset){

	if(!reset){
		problem1count++;
		return 0;
	}
	else{
		int count = problem1count;
		problem1count=0;
		return count;
	}

}



/* @function pi
 * @summary approximates value of pi to the precision of double.
 * @return pi after finding previous sum and next term sum are equal
 */
long double pi (){
	long double i = 2.0;
	long double pi=3.00;

	//set two check points
	long double check1=0.00;
	long double check2=1.00;

	while(check1!=check2){

		//plus successive term
		//increment i
		pi+=4/(i*(i+1)*(i+2));
		i+=2;
		check1=pi;

		//minus successive term
		//increment i
		pi-=4/(i*(i+1)*(i+2));
		check2=pi;
		i+=2;
	}

	return pi;
}


/* @function daysInMonth
 * @summary find the number of months, if invalid, return 0
 * @param 'month' is an input integer of month; can be valid or invalid number
 * @return number of days in month if valid. if invalid month, return 0
 */
unsigned short daysInMonth(unsigned int month){

	//set default return value 0
	unsigned short numDays=0;

	//use switch statement to alter return value
	//only switch value if 'month' is between 1 to 12
	switch (month){

	//change return value to 28 for Feb
	case 2:
		numDays=28;
		break;

	//change return value to 31 for certain months
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		numDays=31;
		break;

	//change return value to 30 for certain months
	case 4:
	case 6:
	case 9:
	case 11:
		numDays=30;
		break;




	}
	return numDays;
}
/**
 * The code in this function is to print the solution to the assignment.
 */
/**
 * @function main
 * @summary test three functions, print results
 *
 * [Problem I Tesing]
 * @variable 'count' is created and used when caling countCalls
 * @test1: call countCalls by inputing 'false' four times then input 'true'. The expected result is 4
 * 		This test was instructed to have by default
 * @test2: call countCalls by inputing 'false' twice then input 'true'. The expected value is 2.
 * 		The reason to call 'false' twice is to ensure that problem1count is reset to 0 after 'true' is input to the function
 * @test3: call countCalls by inputing 'false' once, print result without calling 'true'. The expected result is 0.
 * 		The reason to print result without calling true is to ensure countCalls only return 0 when input is 'false'
 *
 * [Problem II Testing]
 * Call function pi
 *
 *
 * [Problem III Testing]
 * @variables 'month' is the input value to call function daysInMonths;
 * @variables 'days' is used to store the returning value from daysInMonths
 * @test1-12: call daysInMoths with input value from 1-12; expected values should include 31,30, 28
 * 		The reason to call daysInMonth with month 1 to 12 is to ensure all values are accurated.
 * @test13: call daysInMonths with input value 10000; expected value should be 0
 * 		The reason to call daysInMonth with value of 10000 is to ensure the default value is 0 for 'month' over 12
 * @test14: call daysInMonths with input value -1; expected value should be 0
 * 		The reason to call daysInMonth with value of -1 is to ensure the default value is 0 for invalid 'month' value
 */
int main(void) {
	//problem 1 testing
	int count;
	countCalls(false);
	countCalls(false);
	countCalls(false);
	countCalls(false);
	count=countCalls(true);
	printf("countcall is %d \n",count);
	countCalls(false);
	countCalls(false);
	count=countCalls(true);
	printf("countcall is %d \n",count);
	count=countCalls(false);
	printf("countcall is %d \n",count);

	//problem 2 testing
	printf("pi is %.14Lf \n",pi());

	//problem 3 testing
	short month;
	short days;

	month=1;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=2;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=3;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=4;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=5;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=6;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=7;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=8;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=9;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=10;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=11;
	days=daysInMonth(month);
	printf("there are %d days in the  month of %d \n",days,month);

	month=12;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=10000;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

	month=-1;
	days=daysInMonth(month);
	printf("there are %d days in the month of %d \n",days,month);

}
