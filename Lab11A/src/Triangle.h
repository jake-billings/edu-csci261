/*
 * Triangle.h
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */
#pragma once

class Triangle {
private:
	int sideA;
	int sideB;
	int sideC;

	void init(int sideA, int sideB, int sideC);
public:
	Triangle();
	Triangle(int sideA, int sideB, int sideC);

	int getSideA();
	void setSideA(int sideA);
	int getSideB();
	void setSideB(int sideB);
	int getSideC();
	void setSideC(int sideC);

	bool validate();

	int getPerimeter();
	int getArea();
};
