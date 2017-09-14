//============================================================================
// Name        : Lab12A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

const int COUNT = 1000;

int binarySearch(int values[COUNT], int target);
int binarySearch(int values[COUNT], int target, int startIndex, int endIndex);

bool ReadData(string fileName, int array[], int size);
void Swap(int &a, int &b);
void SelectionSort(int array[], int size);
void Print(int array[], int size);

int main() {
	int values[COUNT];

	ReadData("dataFile.txt",values,COUNT);
	SelectionSort(values,COUNT);

	int target;
	cout << "Input Search Term: ";
	cin >> target;

	int index = binarySearch(values,target);

	if (index>=0) {
		cout << "Value " << target << " found at sorted index: " << index << ": "<< values[index] << endl;
	} else {
		cout << "Value not found." << endl;
	}
	return 0;
}

int binarySearch(int values[COUNT], int target, int startIndex, int endIndex) {
	//Any else statements would be redundant, since return statements are used in each if

	//The sort didn't find anything, so return null.
	if (startIndex>endIndex) return -1;

	//Find the middle of the block and check its value
	int middleIndex = (endIndex + startIndex) / 2;

	//The target is greater than expected, so search a lower half.
	if (values[middleIndex] == target) return middleIndex;

	if (values[middleIndex] > target)
		return binarySearch(values,target,startIndex,middleIndex-1);

	//values[middleIndex).gettarget() is less than target.
	return binarySearch(values,target,middleIndex+1,endIndex);
}

int binarySearch(int values[COUNT], int target) {
	return binarySearch(values,target,0,COUNT-1);
}

bool ReadData(string fileName, int array[], int size) {
	//Open a data stream
	ifstream data(fileName);

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		return false;
	}

	int count = 0;
	while (!data.eof() && count < size) {
		data >> array[count++];
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
