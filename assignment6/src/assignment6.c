/**
 * @file assignment6.c
 *
 *
 *
 * @date 10/01/2018
 * @author: HoKang Yu, yu2749luca (github)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	double x,y;

} Point;
typedef struct {
	double radius;
	Point center;
} Circle;
typedef struct {
	Point origin; //top-left corner
	double width, height;
} Rectangle;
/**
 * find the distance between the two points that are input
 * @param a
 * @param b
 * @return distance of two points
 */
double distanceofPoints(const Point* a,const Point* b){
	double deltaX=(a->x-b->x);
	double deltaY=(a->y-b->y);


	return sqrt(deltaX*deltaX+deltaY*deltaY);
}
/**
 * return true if the distance of two centers is less than the sum of of two radius; otherwise, all false.
 * @param circle1
 * @param circle2
 * @return true/false
 */
bool intersectsCircles(const Circle *circle1,Circle* const circle2){
	double d=(distanceofPoints(&circle1->center,&circle2->center));
	double sum=circle1->radius+circle2->radius;
	return d<sum;
}
/**
 * updated the information in boundingbox
 * create a boundingbox that covers the input circle
 * @param circle
 * @param boundingBox
 *
 */
void getBoundingBox(const Circle* circle,Rectangle *boundingBox){
	boundingBox->height=circle->radius*2;
	//printf("testing 1 %f \n", circle->radius);
	boundingBox->width=circle->radius*2;
	boundingBox->origin.x=circle->center.x-circle->radius;
	boundingBox->origin.y=circle->center.y+circle->radius;


}
/*
 *
 * call functions, make test cases, print function
 *
 */
int main(void) {

	Circle circle1={.center={.x=0, .y=0},
	.radius=10};
	Circle circle2={.center={.x=21, .y=0},
	.radius=10};
	Circle circle3={.center={.x=20, .y=0},
	.radius=10};
	Circle circle4={.center={.x=19, .y=0},
	.radius=10};

	//	circle1.center.x=0;circle1.center.y=0;circle1.radius=10;
	//	Circle circle2;
	//	circle2.center.x=21;circle2.center.y=0;circle2.radius=10;
	//	Circle circle3;
	//	circle3.center.x=20;circle3.center.y=0;circle3.radius=10;
	//	Circle circle4;
	//	circle4.center.x=19;circle4.center.y=0;circle4.radius=10;


	bool case1=intersectsCircles(&circle1,&circle2);
	printf("do circle1 and circle 2 intersect: %d\n",case1);
	bool case2=intersectsCircles(&circle1,&circle3);
	printf("do circle1 and circle 3 intersect: %d\n",case2);
	bool case3=intersectsCircles(&circle1,&circle4);
	printf("do circle1 and circle 4 intersect: %d\n",case3);

	Rectangle boundingBox;
	getBoundingBox(&circle1,&boundingBox);
	printf("boundingBox for circle 1 has origin at %.1f,%.1f with width %.1f and height %.1f \n",boundingBox.origin.x,boundingBox.origin.y,boundingBox.width,boundingBox.height);

	getBoundingBox(&circle2,&boundingBox);
	printf("boundingBox for circle 2 has origin at %.1f,%.1f with width %.1f and height %.1f \n",boundingBox.origin.x,boundingBox.origin.y,boundingBox.width,boundingBox.height);

	getBoundingBox(&circle3,&boundingBox);
	printf("boundingBox for circle 3 has origin at %.1f,%.1f with width %.1f and height %.1f \n",boundingBox.origin.x,boundingBox.origin.y,boundingBox.width,boundingBox.height);

	getBoundingBox(&circle4,&boundingBox);
	printf("boundingBox for circle 4 has origin at %.1f,%.1f with width %.1f and height %.1f \n",boundingBox.origin.x,boundingBox.origin.y,boundingBox.width,boundingBox.height);
}

