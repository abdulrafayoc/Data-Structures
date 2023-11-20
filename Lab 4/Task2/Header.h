#pragma once
#include <iostream>

using namespace std;


void find(char** board, int rows, int cols, char* word, int size) {
	int** ids = new int* [size];

	for (int i = 0; i < size; i++) {
		ids[i] = new int[2];
	}

	int i, j;


	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (board[i][j] == word[0]) {
				ids[0][0] = i;
				ids[0][1] = j;
				for (int k = 1; k < size; k++) {
					if (board[i][j + k] == word[k]) {
						ids[k][0] = i;
						ids[k][1] = j + k;
						cout << "here" << endl;
					}
					else if (board[i + k][j] == word[k]) {
						ids[k][0] = i + k;
						ids[k][1] = j;
						cout << "here" << endl; 
					}
					else if (board[i + k][j + k] == word[k]) {
						ids[k][0] = i + k;
						ids[k][1] = j + k;
						cout << "here" << endl; 
					}
					else {
						break;
						cout << "here" << endl; 
					}

					if (k == size - 1) {
						cout << "found" << endl;
						cout << "the ids are: " << endl;
						cout << "row col" << endl;
						for (int l = 0; l < size; l++) {
							cout << ids[l][0] << "    " << ids[l][1] << endl;
						}
						return;
					}
				}
			}

		}

	}
	cout << "not found" << endl;


}
void crosswordd() {
	cout << "Puzzle" << endl;
	cout << "enter the number of rows and columns" << endl;
	int r, c;
	cin >> r >> c;

	char** board = new char* [r];
	for (int i = 0; i < r; i++) {
		board[i] = new char[c];
	}

	for (int i = 0; i < r; i++) {
		cout << "enter the elements of the row " << i + 1 << " : ";
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	cout << "enter the word size you want to search: ";
	int size;
	cin >> size;

	char* word = new char[size];
	cout << "enter the word you want to search: ";
	for (int i = 0; i < size; i++) {
		cin >> word[i];
	}

	find(board, r, c, word, size);
	
}