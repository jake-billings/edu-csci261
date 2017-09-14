/*
 * Triangle.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */

#include "Triangle.h"
#include <math.h>

int Triangle::getSideA() {
	return sideA;
}

void Triangle::setSideA(int sideA) {
	this->sideA = sideA;
}

int Triangle::getSideB() {
	return sideB;
}

void Triangle::setSideB(int sideB) {
	this->sideB = sideB;
}

int Triangle::getSideC() {
	return sideC;
}

void Triangle::setSideC(int sideC) {
	this->sideC = sideC;
}

void Triangle::init(int sideA, int sideB, int sideC) {
	setSideA(sideA);
	setSideB(sideB);
	setSideC(sideC);
}

bool Triangle::validate() {
	if (sideA>sideB+sideC) return false;
	if (sideB>sideA+sideC) return false;
	if (sideC>sideA+sideB) return false;
	return true;
}

int Triangle::getPerimeter() {
	return sideA+sideB+sideC;
}

int Triangle::getArea() {
	int s = (sideA+sideB+sideC)/2;
	return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
}

Triangle::Triangle() {
	init(1,1,1);
}

Triangle::Triangle(int sideA, int sideB, int sideC) {
	init(sideA,sideB,sideC);
}
