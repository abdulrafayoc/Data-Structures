#pragma once

#include <iostream>

using namespace std;

int min(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	cout << "The minimum is: " << min << endl;
	return min;
}

int max(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << "The maximum is: " << max << endl;
	return max;
}