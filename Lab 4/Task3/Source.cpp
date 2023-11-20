#include <iostream>
#include "Header.h"
using namespace std;

int main(){
	cout << "enter the number of rows and columns" << endl;
	int r, c;
	cin >> r >> c;

	int** mtx = new int* [r];
	for (int i = 0; i < r; i++) {
		mtx[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		cout << "enter the elements of the row " << i + 1 << " : ";
		for (int j = 0; j < c; j++) {
			cin >> mtx[i][j];
		}
	}

	checkMarkovMatrix(mtx, r, c);

}