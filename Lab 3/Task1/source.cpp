#include <iostream>
#include "header.h"
using namespace std;

int main() {
	cout << "Enter the size of the array: ";
	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter the " << i + 1 << " element: ";
		cin >> arr[i];
	}
	
	min(arr, size);
	max(arr, size);



}