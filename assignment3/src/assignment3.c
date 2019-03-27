

/**
 * @file assignment-3.c
 * @author  yu2749luca, HoKang Yu
 * @date // Sep 17, 2018
 * This is the third programming assignment for CS 5001.
 */
#include <stdbool.h>
#include <stdio.h>

/**
 *
 * @summary duplicate value n times in the array, and print out the result
 * @param 'n' is the length of array
 * @param 'array' is the array that is being used store value
 * @param 'value' is being duplicated n times in the array
 *
 */


void initArray(unsigned int n, int array[], int value){

	for (int i=0;i<n;i++){
		array [i]=value;
	}




}


/**
 * @summary function wordCount takes an array of char and return the number of words
 * @default assume that all arrays will at least have '\0' (given by the instructor)
 * @param 'str' is a string in the form of array of char.
 * 		  'str' is an input string being used to count the number of words.
 * @return the number of words within the string
 */

int wordCount(char str []){

	int wordCount=0;
	int i=0;
	while(str[i]!='\0'){

		if(str[i]==' '){
			i++;
		}
		else if((str[i]!=' ')&&((str[i+1]==' '))){
			//count word if a character is followed by space
			wordCount++;
			i++;
		}
		else if ((str[i]!=' ')&&(str[i+1]=='\0')){
			//count last word if it reaches terminator (\0)
			wordCount++;
			i++;
		}
		else {
			//catch exception and still increment i
			//avoid infinite loop
			i++;
		}
	}
	return (int)wordCount;
}

/**
 * @summary main is being used to test functions
 * additional info for each test is shown below
 *
 * @return
 */


int main(void) {

	//pass a array size of 0 with value of 25
	//expected result should be zero
	//this test case is to test if size of 0 can be implemented or not
	int n=0,value=25;
	int a0 [n];
	initArray(n,a0,value);
	printf("initArray(%d, %s, %d) result: ",n,"a0",value);
	printf("{");
	for (int i=0;i<n;i++){
		if (i<n-1){
			printf(" %d,", a0[i]);
		}
		else {
			printf(" %d ",a0[i]);
		}
	}
	printf("} \n");


	//pass a array size of 1 with value of 42
	//expected result should be one 42.
	//this test case is to test if 42 can be printed one time
	n=1;value=42;
	int a1 [n];
	printf("initArray(%d, %s, %d) result: ",n,"a1",value);
	initArray(n,a1,42);
	printf("{");
	for (int i=0;i<n;i++){
		if (i<n-1){
			printf(" %d,", a1[i]);
		}
		else {
			printf(" %d ",a1[i]);
		}
	}
	printf("} \n");

	//pass a array size of 3 with value of 88
	//expected result should be three 88.
	//this test case is to test if 88 can be printed three times
	n=3;value=88;
	int a3 [n];
	printf("initArray(%d, %s, %d) result: ",n,"a3",value);
	initArray(n, a3, 88);
	printf("{");
	for (int i=0;i<n;i++){
		if (i<n-1){
			printf(" %d,", a3[i]);
		}
		else {
			printf(" %d ",a3[i]);
		}
	}
	printf("} \n");

	//pass a array size of 6 with value of 14
	//expected result should be six 14.
	//this test case is to test if 14 can be printed 6 times
	n=6;value=14;
	int a6 [n];
	printf("initArray(%d, %s, %d) result: ",n,"a6",value);
	initArray(n, a6, 14);
	printf("{");
	for (int i=0;i<n;i++){
		if (i<n-1){
			printf(" %d,", a6[i]);
		}
		else {
			printf(" %d ",a6[i]);
		}
	}
	printf("} \n");

	int count=0;
	int len=0;

	//this test case pass only null value into the function
	//the expected return word count shall be 0
	//this is to test if the function can correctedly read an empty array
	char b1 []={'\0'};
	count=wordCount(b1);
	len=strlen(b1);
	printf("\"%s\" length: %d, word count: %d \n",b1,len,count);

	//this test case pass one word and no space into the function
	//the expected return word count shall be 1
	//this is to test if the function can correctedly read a word
	char b2 []={'d','o','g','\0'};
	count=wordCount(b2);
	len=strlen(b2);
	printf("\"%s\" length: %d, word count: %d \n",b2,len,count);

	//this test case pass two words and one space into the function
	//the expected return word count shall be 2
	//this is to test if the function can correctedly distinct space and word
	char b3 []={'t','w','o',' ','w','o','r','d','s','\0'};
	count=wordCount(b3);
	len=strlen(b3);
	printf("\"%s\" length: %d, word count: %d \n",b3,len,count);

	//this test case pass three words and two spaces into the function
	//the expected return word count shall be 3
	//this is to test if the function can correctedly distinct spaces and words
	char b4 []={'t','h','e',' ','q','u','i','c','k',' ','b','r','o','w','n',' ','f','o','x','\0'};
	count=wordCount(b4);
	len=strlen(b4);
	printf("\"%s\" length: %d, word count: %d \n",b4,len,count);

	//this test case pass two words and one space into the function
	//the expected return word count shall be 2
	//this is to test if the function can correctedly read string instead of character
	char b5 []={"hello world"};
	count=wordCount(b5);
	len=strlen(b5);
	printf("\"%s\" length: %d, word count: %d \n",b5,len,count);

	//this test case pass one character and one space into the function
	//the expected return word count shall be 1
	//this is to test if the function can correctedly read only one character
	char b6 []={"a"};
	count=wordCount(b6);
	len=strlen(b6);
	printf("\"%s\" length: %d, word count: %d \n",b6,len,count);

	//this test case pass multiple spaces with no valid character
	//the expected return word count shall be 0
	//this is to test if the function can correctedly read when there are no words
	char b7 []={' ',' ',' ','\0'};
	count=wordCount(b7);
	len=strlen(b7);
	printf("\"%s\" length: %d, word count: %d \n",b7,len,count);

	//this test case pass multiple spaces with no valid character
	//the expected return word count shall be 0
	//this is to test if the function can correctedly read when there are no words
	char b8 []={"         "};
	count=wordCount(b8);
	len=strlen(b8);
	printf("\"%s\" length: %d, word count: %d \n",b8,len,count);

	//this test case pass one word with many unnecessary spaces
	//the expected return word count shall be 1
	//this is to test if the function can correctedly distinct word and multiple meaningless spaces
	char b9 []={"   hello   "};
	count=wordCount(b9);
	len=strlen(b9);
	printf("\"%s\" length: %d, word count: %d \n",b9,len,count);


}
