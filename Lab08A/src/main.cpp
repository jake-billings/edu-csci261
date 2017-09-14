/* CSCI261 Lab 08A: Matrix transposition
 *
 * Author: Jake Billings
 */

#include <iostream>
#include <fstream>

using namespace std;

const int NROWS = 8;
const int NCOLS = 4;

void readMatrix(int dest[NROWS][NCOLS]);
void printMatrix(const int matrix[NROWS][NCOLS]);
void printMatrix(const int matrix[NCOLS][NROWS]);
void transposeMatrix(const int matrix[NROWS][NCOLS], int transposed[NCOLS][NROWS]);
void writeMatrix(const int matrix[NCOLS][NROWS]);

int main() {
	int matrix[NROWS][NCOLS];
	int transposed[NCOLS][NROWS];

	readMatrix(matrix);

	printMatrix(matrix);

	transposeMatrix(matrix,transposed);

	printMatrix(transposed);

	writeMatrix(transposed);

	return 0;
}

void readMatrix(int dest[NROWS][NCOLS]) {
	//Open a data stream
	ifstream data("dataIn.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	int x = 0;
	int y = 0;
	while (!data.eof()&&y<NROWS) {
		data >> dest[y][x];
		x++;
		if (x >= NCOLS) {
			x=0;
			y++;
		}
	}
}

void printMatrix(const int matrix[NROWS][NCOLS]) {
	for (int x = 0; x < NROWS; x++) {
		for (int y = 0; y < NCOLS; y++) {
			cout << matrix[x][y] << "\t";
		}
		cout << endl;
	}
}
void printMatrix(const int matrix[NCOLS][NROWS]) {
	for (int x = 0; x < NCOLS; x++) {
		for (int y = 0; y < NROWS; y++) {
			cout << matrix[x][y] << "\t";
		}
		cout << endl;
	}
}

void transposeMatrix(const int matrix[NROWS][NCOLS], int transposed[NCOLS][NROWS]) {
	for (int x = 0; x < NROWS; x++) {
		for (int y = 0; y < NCOLS; y++) {
			transposed[y][x] = matrix[x][y];
		}
	}
}

void writeMatrix(const int matrix[NCOLS][NROWS]) {
	//Open a data stream
	ofstream data("dataOut.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	for (int x = 0; x < NCOLS; x++) {
		for (int y = 0; y < NROWS; y++) {
			data << matrix[x][y] << "\t";
		}
		data << endl;
	}

}
