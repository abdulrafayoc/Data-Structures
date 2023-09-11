#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include "data.h"
#include "sorting.h"
using namespace std;

int main() {
	
	Employee* employees = getData();
	
	

	//for (int i = 0; i < 10; i++) {
	//	employees[i].print();
	//	cout << endl;
	//}

	//performanceAnalysis(employees);

	//salaryAnalysis(employees);

	//tenureAnalysis(employees);
	selectionSortByTenure(employees);
	//insertionSort(employees);
	//bubbleSort(employees);

	for (int i = 0; i < 10; i++) {
		employees[i].print();
		cout << endl <<endl;
	}

	return 0;
}