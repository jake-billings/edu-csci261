/* CSCI261 Lab 09A2: Selection Sort
 *
 * Author: Jake Billings
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool ReadData(string fileName, int array[], int size);

void Swap(int &a, int &b);

void SelectionSort(int array[], int size, bool ascending);

void Print(int array[], int size);

int main() {
	const int SIZE = 100;
	int data[2][SIZE];
	ReadData("data/data2sort.txt",data[0],SIZE);
	for (int i = 0; i < SIZE; i++) {
		data[1][i] = data[0][i];
	}
	Print(data[0],SIZE);
	Print(data[1],SIZE);
	SelectionSort(data[0],SIZE,true);
	SelectionSort(data[1],SIZE,false);
	Print(data[0],SIZE);
	Print(data[1],SIZE);

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

void SelectionSort(int array[], int size, bool ascending) {
	for (int i = 0; i < size - 1; i++) {
		int minimumIndex = i;

		for (int j = i+1; j <  size; j++) {
			if ((array[j] < array[minimumIndex])==ascending) {
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
