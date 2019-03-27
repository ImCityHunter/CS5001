/**
 * @file animal.c
 *
 *
 *
 * @date 9/25/2018
 * @author: HoKang Yu, yu2749luca (github)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


const unsigned Animal_kinds=10;
typedef unsigned int Zoo [Animal_kinds];
typedef enum {anteater, bear,chita,elephant, giraffe, lion,monkey, rhinoceros, tiger, zebra} Animal ;

/**
 * initialized Zoo
 * set all array value to 0
 */
void makeZoo(Zoo aZoo){
	for (int i=0;i<Animal_kinds;i++){

		aZoo[i]=0;
	}
}
/**
 *
 * @param aZoo
 * @param anAnimal
 * @return new count of the animal that is passed into the function
 */
unsigned int addAnimal(Zoo aZoo, Animal anAnimal) {
	return aZoo[anAnimal]+=1;;
}
/**
 *
 * @param anAnimal
 * @return the name of the animal that is passed into the function
 */

const char* getAnimalName(Animal anAnimal) {
	static const char *animalNames[]={"anteater", "bear","chita","elephant","giraffe","lion","monkey","rhinoceros","tiger","zebra"};
	return animalNames[anAnimal];
}
/**
 * print the entire of the zoo
 * one animal per line with the count in a blank-padded field of 3 digits (%3u)
 * followed by a tab character ('\t')
 * followed by the name of the animal.
 */
void printZoo(const Zoo aZoo) {

	for (Animal anAnimal=anteater;anAnimal<=zebra;anAnimal++){
		unsigned int amount=aZoo[anAnimal];
		printf("%3u\t%s\n",amount,getAnimalName(anAnimal));
	}
}
/**
 *
 * Make a Zoo variable, initialize that zoo
 * add animals into the zoo
 * print the animal and the animal count that is added
 * print the entire zoo count
 */

int main(void) {
	Zoo aZoo;
	makeZoo(aZoo);
	for (Animal a=anteater;a<=zebra;a++){
			for (int i=0;i<a;i++){
			printf("Added %s count: %u\n",getAnimalName(a),addAnimal(aZoo,a));}
	}


	printZoo(aZoo);
}

