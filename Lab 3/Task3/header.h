#pragma once

#include <iostream>

using namespace std;

char** words_to_sentence(int row, int col) {
	char** sentence = new char* [row];
	for (int i = 0; i < row; i++) {
		sentence[i] = new char[col];
	}

	for (int i = 0; i < row; i++) {
		cout << "Enter word " << i + 1 << ": ";
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			if (j < str.length()) {
			sentence[i][j] = str[j];
			}
			else {
				sentence[i][j] = ' ';
			}
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << sentence[i][j];
		}
		cout << " ";
	}
	return NULL;
}