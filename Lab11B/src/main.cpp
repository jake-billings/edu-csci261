//============================================================================
// Name        : Lab11B
// Author      : Jake Billings
//============================================================================

#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	Date d;
	cout << d.getDay() << endl;
	cout << d.getMonth() << endl;
	cout << d.getAdjustedYear() << endl;

	Date d1(1,8,1876);
	cout << d1.getDay() << endl;
	cout << d1.getMonth() << endl;
	cout << d1.getAdjustedYear() << endl;
	return 0;
}
