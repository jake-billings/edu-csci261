/**
 * HW09:
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = WIDTH;

int getRandomIncompleteIndex(char data[WIDTH][HEIGHT]);
void placeDiscInLowestPosition(char column[HEIGHT], const char color);
void writeBoardToStream(char board[WIDTH][HEIGHT], ostream& output);
void writeBoardToFile(char board[WIDTH][HEIGHT]);
void printBoard(char board[WIDTH][HEIGHT]);
void readBoardFromFile(char board[WIDTH][HEIGHT]);
void transposeMatrix(const char matrix[WIDTH][HEIGHT], char transposed[HEIGHT][WIDTH]);
bool checkForVictory(const char row[HEIGHT], const char color);
void checkForVictories(const char board[WIDTH][WIDTH], int& redCount, int& greenCount);

int main() {
	srand(time(0));

	char board[WIDTH][HEIGHT];

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			board[x][y]='b';
		}
	}

	for (int i = 0; i < 20; i++) {
		placeDiscInLowestPosition(board[getRandomIncompleteIndex(board)],'r');
		placeDiscInLowestPosition(board[getRandomIncompleteIndex(board)],'g');
	}
	writeBoardToFile(board);

	char board2[WIDTH][HEIGHT];

	readBoardFromFile(board2);

	int redRowCount = 0;
	int greenRowCount = 0;
	int redColumnCount = 0;
	int greenColumnCount = 0;

	char transposed[HEIGHT][WIDTH];
	transposeMatrix(board2,transposed);

	checkForVictories(board,redRowCount,greenRowCount);
	checkForVictories(transposed,redColumnCount,greenColumnCount);

	cout << "Red won " << redRowCount << " rows." << endl;
	cout << "Green won " << greenRowCount << " rows." << endl;
	cout << "Red won " << redColumnCount << " columns." << endl;
	cout << "Green won " << greenColumnCount << " columns." << endl;
}

int getRandomIncompleteIndex(char data[WIDTH][HEIGHT]) {
	vector<int> incompleteIndices;
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			if (data[x][y]=='b') {
				incompleteIndices.push_back(x);
				break;
			}
		}
	}
	if (incompleteIndices.size()>0) return incompleteIndices.at(rand()%incompleteIndices.size());
	return -1;
}

void placeDiscInLowestPosition(char column[HEIGHT], const char color) {
	for (int i = 0; i < HEIGHT; i++) {
		if (column[i] == 'b') {
			column[i] = color;
			break;
		}
	}
}

void writeBoardToStream(char board[WIDTH][HEIGHT], ostream& output) {
	for (int y = HEIGHT-1; y >= 0; y--) {
		for (int x = 0; x < WIDTH; x++) {
			output << board[x][y] << " ";
		}
		output << endl;
	}
}

void writeBoardToFile(char board[WIDTH][HEIGHT]) {
	ofstream output("data/board.txt");
	if (output.fail()) {
		cerr << "Problem opening output file" << endl;
		exit(1);
	}
	writeBoardToStream(board,output);
	output.close();
}

void printBoard(char board[WIDTH][HEIGHT]) {
	writeBoardToStream(board,cout);
}

void readBoardFromFile(char board[WIDTH][HEIGHT]) {
	ifstream input("data/board.txt");
	for (int y = HEIGHT-1; y >= 0; y--) {
		for (int x = 0; x < WIDTH; x++) {
			input >> board[x][y];
		}
	}

}

void transposeMatrix(const char matrix[WIDTH][HEIGHT], char transposed[HEIGHT][WIDTH]) {
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			transposed[y][x] = matrix[x][y];
		}
	}
}

bool checkForVictory(const char row[HEIGHT], const char color) {
	int sequentialCount = 0;
	for (int i = 0; i < HEIGHT; i++) {
		if (row[i]==color) {
			sequentialCount++;
		} else {
			sequentialCount = 0;
		}
		if (sequentialCount >= 4) {
			return true;
		}
	}
	return false;
}

void checkForVictories(const char board[WIDTH][WIDTH], int& redCount, int& greenCount) {
	for (int x = 0; x < WIDTH; x++) {
		if (checkForVictory(board[x],'r')) redCount++;
		if (checkForVictory(board[x],'g')) greenCount++;
	}
}
