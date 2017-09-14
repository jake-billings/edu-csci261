/**
 * Lab09B: Meet Vectors
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout << "Witness my exciting first use of vectors!" << endl;
	cout << "Enter as many letters as you like, or ! to quit. Mmmkay?" << endl;

	vector<char> chars;

	char input;
	do {
		chars.push_back(input);
		cout << "Enter a letter: ";
		cin >> input;
	} while (input!='!');

	cout << "Great. You entered: ";

	for (int i = 0; i < chars.size(); i++) {
		cout << chars.at(i);
	}

	cout << endl;

	cout << "This first letter you entered was " << chars.front() << endl;
	cout << "This last letter you entered was " << chars.back() << endl;

	return 0;
}
