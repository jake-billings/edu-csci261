/* CSCI 261 Lab 04B: 99 Bottles of Hand Sanitizer
 *
 * Author: Jake Billings
 * 01/30/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	for (int i=number;i>1;i--) {
		cout << i << " bottles of hand sanitizer on the wall," << endl;
		cout << i << " bottles of hand sanitizer!" << endl;
		cout << "Take one down! Pass it around!," << endl;
		if (i-1==1) {
			cout << "1 bottle of hand sanitizer on the wall!" << endl;
		} else {
			cout << i-1 << " bottles of hand sanitizer on the wall!" << endl;
		}
		cout << endl;
	}
	cout << "1 bottle of hand sanitizer on the wall," << endl;
	cout << "1 bottle of hand sanitizer!" << endl;
	cout << "Take one down! Pass it around!," << endl;
	cout << "Press any key to continue." << endl;
}
