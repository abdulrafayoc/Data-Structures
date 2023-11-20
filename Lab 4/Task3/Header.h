#pragma once

#include <iostream>

using namespace std;

bool checkMarkovMatrix(int** mtx, int row, int col) {
	for (int i = 0; i < row; i++) {
		int sum = 0;
		for (int j = 0; j < col; j++) {
			sum += mtx[i][j];
		}
		if (sum == 1) {
			cout << "this is a Markov matrix" << endl;
			return true;
		}
		else {
			cout << "this is not a Markov matrix" << endl;
			return false;
		}


	}
}
