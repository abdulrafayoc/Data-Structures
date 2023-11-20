#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include "data.h"
#include "sorting.h"
using namespace std;

int main() {

	Employee* employees = getData();
	int choice = 1;
	while (choice != 0) {
		cout << "---------------------------" << endl;
		cout << "1. Performance Analysis" << endl;
		cout << "2. Salary Analysis" << endl;
		cout << "3. Tenure Analysis" << endl;
		cout << "4. Selection Sort by Tenure" << endl;
		cout << "5. Bubble Sort by Tenure" << endl;
		cout << "6. Insertion Sort by Tenure" << endl;
		cout << "7. Selection Sort by Salary" << endl;
		cout << "8. Bubble Sort by Salary" << endl;
		cout << "9. Insertion Sort by Salary" << endl;
		cout << "10. Display Data" << endl;
		cout << "0. Exit" << endl;
		cout << "---------------------------" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		cout << "----------------------------" << endl;
		switch (choice) {
		case 1:
			performanceAnalysis(employees);
			break;
		case 2:
			salaryAnalysis(employees);
			break;
		case 3:
			tenureAnalysis(employees);
			break;
		case 4:
			selectionSortByTenure(employees);
			break;
		case 5:
			bubbleSortByTenure(employees);
			break;
		case 6:
			insertionSortByTenure(employees);
			break;
		case 7:
			selectionSortBySalary(employees);
			break;
		case 8:
			bubbleSortBySalary(employees);
			break;
		case 9:
			insertionSortBySalary(employees);
			break;
		case 10:
			for (int i = 0; i < 10; i++) {
				employees[i].print();
				cout << endl << endl;
			}
			break;
		default:
			return 0;
			break;
		}



	}

	return 0;
}