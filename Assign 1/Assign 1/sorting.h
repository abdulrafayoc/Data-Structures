#pragma once

#include <iostream>
#include "header.h"

using namespace std;

// Students are tasked with implementing and applying a sorting algorithm
//(e.g., Selection Sort, Insertion Sort, or Bubble Sort) to rank employees in
//ascending order based on their salaries.Once the sorting algorithm is applied,
//students should provide a ranked list of employees along with their respective
//salaries

void swap(Employee& xp, Employee& yp) {
	Employee temp = xp;
	xp = yp;
	yp = temp;
}

void selectionSortBySalary(Employee* employees) {
	int i, j, min_idx;
	int n = 10;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (employees[j].getSalary() < employees[min_idx].getSalary()) {
				min_idx = j;
			}

		swap(employees[min_idx], employees[i]);
	}
}

void insertionSortBySalary(Employee* employees) {
	int i, j;
	int n = 10;
	Employee key;

	for (i = 1; i < n; i++)
	{
		key = employees[i];
		j = i - 1;

		while (j >= 0 && employees[j].getSalary() > key.getSalary())
		{
			employees[j + 1] = employees[j];
			j = j - 1;
		}
		employees[j + 1] = key;
	}
}

void bubbleSortBySalary(Employee* employees) {
	int i, j;
	int n = 10;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (employees[j].getSalary() > employees[j + 1].getSalary()) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}
}

void selectionSortByTenure(Employee* employees) {
	int i, j, min_idx;
	int n = 10;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (employees[j].getTenure() < employees[min_idx].getTenure()) {
				min_idx = j;
			}

		swap(employees[min_idx], employees[i]);
	}
}

void insertionSortByTenure(Employee* employees) {
	int i, j;
	int n = 10;
	Employee key;

	for (i = 1; i < n; i++)
	{
		key = employees[i];
		j = i - 1;

		while (j >= 0 && employees[j].getTenure() > key.getTenure())
		{
			employees[j + 1] = employees[j];
			j = j - 1;
		}
		employees[j + 1] = key;
	}
}

void bubbleSortByTenure(Employee* employees) {
	int i, j;
	int n = 10;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (employees[j].getTenure() > employees[j + 1].getTenure()) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}
}
