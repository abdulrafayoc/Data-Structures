#include <iostream>
#include "header.h"

using namespace std;

int main() {
	cout << "Enter row: ";
	int row;
	cin >> row;
	cout << "Enter col: ";
	int col;
	cin >> col;

	words_to_sentence(row, col);
}