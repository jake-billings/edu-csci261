/* CSCI261 Lab 09A: Selection Sort
 *
 * Author: Jake Billings
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool ReadData(string fileName, int array[], int size);

void Swap(int &a, int &b);

void SelectionSort(int array[], int size);

void Print(int array[], int size);

int main() {
	const int SIZE = 100;
	int data[SIZE];
	ReadData("data/data2sort.txt",data,SIZE);
	Print(data,SIZE);
	SelectionSort(data,SIZE);
	Print(data,SIZE);

}

bool ReadData(string fileName, int array[], int size) {
	//Open a data stream
	ifstream data("data/data2sort.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		return false;
	}

	int count = 0;
	while (!data.eof() && count < size) {
		int n;
		data >> n;
		array[count++] = n;
	}

	return true;
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minimumIndex = i;

		for (int j = i+1; j <  size; j++) {
			if (array[j] < array[minimumIndex]) {
				minimumIndex = j;
			}
		}

		swap(array[minimumIndex],array[i]);
	}
}

void Print(int array[], int size) {
	for (int i=0;i<size-1;i++) {
		cout << array[i] << ", ";
	}
	cout << array[size-1] << endl;
}
