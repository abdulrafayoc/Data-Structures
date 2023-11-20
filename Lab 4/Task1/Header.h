#pragma once

#include <iostream>

using namespace std;

void insertionSort(int* arr, int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void bubbleSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
	}
}

void selectionSort(int* arr, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
void puzzle() {
	cout << "Puzzle" << endl;
	cout << "enter the number of rows and columns" << endl;
	int r, c;
	cin >> r >> c;
	if (r != 3) {
		cout << "invalid input" << endl;
		return;
	}

	int** arr = new int* [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];
	}
	for (int i = 0; i < r; i++) {
		cout << "enter the elements of the row " << i + 1 << " : ";
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				for (int k = j; k < c; k++) {
					arr[i][k] = -9;
				}
				break;
			}
		}
	}

	insertionSort(arr[0], c);
	selectionSort(arr[1], c);
	bubbleSort(arr[2], c);



	// print
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -9) {
				cout << arr[i][j] << "   ";
			}
		}
		cout << endl;
	}
}