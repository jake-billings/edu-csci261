//============================================================================
// Name        : Lab11A
// Author      : Jake Billings
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>
#include "Triangle.h"

using namespace std;

int main() {
	const int NUM_TRIANGLES = 100;

	srand(time(0));

	vector<Triangle> triangles;

	for (int i = 0; i < NUM_TRIANGLES; i++) {
		triangles.push_back(Triangle(rand()%100,rand()%100,rand()%100));
	}

	int valid = 0;
	for (int i = 0; i < NUM_TRIANGLES; i++) {
		cout << "Triangle " << i+1 << " is " << (triangles.at(i).validate()?"valid":"invalid") << endl;
		if (triangles.at(i).validate()) {
			cout << "The area of Triangle " << i << " is " << triangles.at(i).getArea() << endl;
			valid++;
		}
	}

	cout << valid << " triangles were valid." << endl; // prints !!!Hello World!!!
	return 0;
}
