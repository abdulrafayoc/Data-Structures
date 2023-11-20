#pragma once

#include <iostream>
#include <chrono>
#include "header.h"
#include <iomanip>
using namespace std;


void swap(Employee& x1, Employee& x2) {
	Employee temp = x1;
	x1 = x2;
	x2 = temp;
}

int gettime() {
	return chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

void selectionSortBySalary(Employee* employees) {
	int i, j;

	int swapCount = 0, comparisionCount = 0;
	int n = 10;
	int start = gettime();

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++) {
			comparisionCount++;
			if (employees[j].getSalary() < employees[i].getSalary()) {
				swap(employees[j], employees[i]);
			}
		}
		swapCount++;

	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;

}

void insertionSortBySalary(Employee* employees) {
	int i, j;
	int swapCount = 0, comparisionCount = 0;
	int n = 10;
	Employee key;
	int start = gettime();

	for (i = 1; i < n; i++)
	{
		key = employees[i];
		j = i - 1;

		comparisionCount++;
		while (j >= 0 && employees[j].getSalary() > key.getSalary())
		{
			comparisionCount++;
			employees[j + 1] = employees[j];
			j = j - 1;
			swapCount++;

		}
		employees[j + 1] = key;
	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;
}

void bubbleSortBySalary(Employee* employees) {
	int i, j;
	int n = 10;
	int swapCount = 0, comparisionCount = 0;
	int start = gettime();

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			comparisionCount++;
			if (employees[j].getSalary() > employees[j + 1].getSalary()) {
				swap(employees[j], employees[j + 1]);
				swapCount++;

			}
		}
	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;
}

void selectionSortByTenure(Employee* employees) {
	int i, j;

	int swapCount = 0, comparisionCount = 0;
	int n = 10;
	int start = gettime();

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++) {
			comparisionCount++;
			if (employees[j].getTenure() < employees[i].getTenure()) {
				swap(employees[j], employees[i]);
			}
		}
		swapCount++;

	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;
}

void insertionSortByTenure(Employee* employees) {
	int i, j;
	int n = 10;
	int swapCount = 0, comparisionCount = 0;
	Employee key;
	int start = gettime();

	for (i = 1; i < n; i++)
	{
		key = employees[i];
		j = i - 1;
		comparisionCount++;

		while (j >= 0 && employees[j].getTenure() > key.getTenure())
		{
			comparisionCount++;
			swapCount++;

			employees[j + 1] = employees[j];
			j = j - 1;
		}
		employees[j + 1] = key;
	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;
}

void bubbleSortByTenure(Employee* employees) {
	int i, j;
	int swapCount = 0, comparisionCount = 0;
	int start = gettime();
	int n = 10;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			comparisionCount++;
			if (employees[j].getTenure() > employees[j + 1].getTenure()) {
				swapCount++;
				swap(employees[j], employees[j + 1]);
			}
		}
	}
	int end = gettime();

	cout << "Time taken by algorithm: " << end - start << " microseconds" << endl;
	cout << "Number of swaps: " << swapCount << endl;
	cout << "Number of comparisions: " << comparisionCount << endl;
}
