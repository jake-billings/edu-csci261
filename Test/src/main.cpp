/*
 * main.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: jakebillings
 */
#include <iostream>

using namespace std;

const int COLSIZE = 3;

int fun(const int a[][COLSIZE], int n);

int main() {
	int sum(0);
	int x[4][4] = { {1,2,3,4},{5,6,7,8},{9,7,2,3},{2,1,4,0} };
	for(int i =1; i <4; i++)
	for(int j =0; j < 4;++j) if (x[i][j] > x[i-1][j])
	sum++;
	cout<<sum;
}
