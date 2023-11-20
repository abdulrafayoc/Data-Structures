#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "header.h"

using namespace std;

Employee* getData() {
	fstream file;
	file.open("../Employeedata.txt");
	string str;

	string* names = new string[10];
	string* IDs = new string[10];
	int* salaries = new int[10];
	string* datesOfJoining = new string[10];
	string* designations = new string[10];


	file.clear();
	file.seekg(0, ios::beg);
	int i;
	i = 0;
	while (getline(file, str)) {
		if (str.find("Employee Name:") != string::npos) { //string :: npos is the end of the string
			names[i] = str.substr(18, str.length() - 18);
			i++;
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	i = 0;
	while (getline(file, str)) {
		if (str.find("EMP") != string::npos) {
			IDs[i] = str.substr(14, str.length() - 14);
			i++;
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	i = 0;
	while (getline(file, str)) {
		if (str.find("$") != string::npos) {
			str = str.substr(10, str.length() - 10);
			str.erase(remove(str.begin(), str.end(), ','), str.end()); 
			salaries[i] = stoi(str);
			i++;
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	i = 0;
	while (getline(file, str)) {
		if (str.find("Date of Joining:") != string::npos) {
			datesOfJoining[i] = str.substr(18, str.length() - 18);
			i++;
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	i = 0;
	while (getline(file, str)) {
		if (str.find("Designation:") != string::npos) {
			designations[i] = str.substr(14, str.length() - 14);
			i++;
		}
	}
	file.close();

	Employee* employees = new Employee[10];
	for (int i = 0; i < 10; i++) {
		employees[i] = Employee(names[i], IDs[i], salaries[i], datesOfJoining[i], designations[i]);
	}

	delete[] names;
	delete[] IDs;
	delete[] salaries;
	delete[] datesOfJoining;
	delete[] designations;

	names = nullptr;
	IDs = nullptr;
	salaries = nullptr;
	datesOfJoining = nullptr;
	designations = nullptr;


	return employees;
}


void performanceAnalysis(Employee* employees) {
	int totalSalary = 0;
	for (int i = 0; i < 10; i++) {
		totalSalary += employees[i].getSalary();
	}
	int averageSalary = totalSalary / 10;

	int totalTenure = 0;
	for (int i = 0; i < 10; i++) {
		totalTenure += employees[i].getTenure();
	}
	int averageTenure = totalTenure / 10;

	int softwareEngineer = 0;
	int seniorSoftwareEngineer = 0;
	int dataScientist = 0;
	int projectManager = 0;
	int seniorDataAnalyst = 0;
	int uxDesigner = 0;
	int qaAnalyst = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getDesignation() == "Software Engineer") {
			softwareEngineer++;
		}
		else if (employees[i].getDesignation() == "Senior Software Engineer") {
			seniorSoftwareEngineer++;
		}
		else if (employees[i].getDesignation() == "Data Scientist") {
			dataScientist++;
		}
		else if (employees[i].getDesignation() == "Project Manager") {
			projectManager++;
		}
		else if (employees[i].getDesignation() == "Senior Data Analyst") {
			seniorDataAnalyst++;
		}
		else if (employees[i].getDesignation() == "UX Designer") {
			uxDesigner++;
		}
		else if (employees[i].getDesignation() == "Quality Assurance Analyst") {
			qaAnalyst++;
		}
	}

	float longestTenure = 0;
	int longestTenureIndex = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getTenure() > longestTenure) {
			longestTenure = employees[i].getTenure();
			longestTenureIndex = i;
		}
	}

	cout << "Average salary in the company: " << averageSalary << endl;
	cout << "Total number of employees: " << 10 << endl;
	cout << "Average tenure(in years) of employees in the company: " << averageTenure << endl;
	cout << "Distribution of employees based on their designations: " << endl;
	cout << "\tNumber of Software Engineers: " << softwareEngineer << endl;
	cout << "\tNumber of Senior Software Engineers: " << seniorSoftwareEngineer << endl;
	cout << "\tNumber of Data Scientists: " << dataScientist << endl;
	cout << "\tNumber of Project Managers: " << projectManager << endl;
	cout << "\tNumber of Senior Data Analysts: " << seniorDataAnalyst << endl;
	cout << "\tNumber of UX Designers: " << uxDesigner << endl;
	cout << "\tNumber of QA Analysts: " << qaAnalyst << endl;
	cout << "Employee with longest tenure: " << endl; employees[longestTenureIndex].print();




}


void salaryAnalysis(Employee* employees) {
	int highestSalary = 0;


	for (int i = 0; i < 10; i++) {
		if (employees[i].getSalary() > highestSalary) {
			highestSalary = employees[i].getSalary();
		}
	}

	int lowestSalary = 999999999;
	for (int i = 0; i < 10; i++) {
		if (employees[i].getSalary() < lowestSalary) {
			lowestSalary = employees[i].getSalary();
		}
	}

	int salaryRange = highestSalary - lowestSalary;

	int medianSalary = 0;
	int* salaries = new int[10];
	for (int i = 0; i < 10; i++) {
		salaries[i] = employees[i].getSalary();
	}
	int size = 10;
	sort(salaries, salaries + size);
	if (size % 2 == 0) {
		medianSalary = (salaries[size / 2 - 1] + salaries[size / 2]) / 2;
	}
	else {
		medianSalary = salaries[(size / 2)];
	}

	int softwareEngineer = 0;
	int seniorSoftwareEngineer = 0;
	int dataScientist = 0;
	int projectManager = 0;
	int seniorDataAnalyst = 0;
	int uxDesigner = 0;
	int qaAnalyst = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getDesignation() == "Software Engineer") {
			softwareEngineer += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "Senior Software Engineer") {
			seniorSoftwareEngineer += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "Data Scientist") {
			dataScientist += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "Project Manager") {
			projectManager += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "Senior Data Analyst") {
			seniorDataAnalyst += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "UX Designer") {
			uxDesigner += employees[i].getSalary();
		}
		else if (employees[i].getDesignation() == "Quality Assurance Analyst") {
			qaAnalyst += employees[i].getSalary();
		}
	}

	int numberOfSoftwareEngineers = 0;
	int numberOfSeniorSoftwareEngineers = 0;
	int numberOfDataScientists = 0;
	int numberOfProjectManagers = 0;
	int numberOfSeniorDataAnalysts = 0;
	int numberOfUXDesigners = 0;
	int numberOfQAAnalysts = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getDesignation() == "Software Engineer") {
			numberOfSoftwareEngineers++;
		}
		else if (employees[i].getDesignation() == "Senior Software Engineer") {
			numberOfSeniorSoftwareEngineers++;
		}
		else if (employees[i].getDesignation() == "Data Scientist") {
			numberOfDataScientists++;
		}
		else if (employees[i].getDesignation() == "Project Manager") {
			numberOfProjectManagers++;
		}
		else if (employees[i].getDesignation() == "Senior Data Analyst") {
			numberOfSeniorDataAnalysts++;
		}
		else if (employees[i].getDesignation() == "UX Designer") {
			numberOfUXDesigners++;
		}
		else if (employees[i].getDesignation() == "Quality Assurance Analyst") {
			numberOfQAAnalysts++;
		}
	}

	int averageSoftwareEngineer = softwareEngineer / numberOfSoftwareEngineers;
	int averageSeniorSoftwareEngineer = seniorSoftwareEngineer / numberOfSeniorSoftwareEngineers;
	int averageDataScientist = dataScientist / numberOfDataScientists;
	int averageProjectManager = projectManager / numberOfProjectManagers;
	int averageSeniorDataAnalyst = seniorDataAnalyst / numberOfSeniorDataAnalysts;
	int averageUXDesigner = uxDesigner / numberOfUXDesigners;
	int averageQAAnalyst = qaAnalyst / numberOfQAAnalysts;


	cout << "Highest Salary: " << highestSalary << endl;
	cout << "Lowest Salary: " << lowestSalary << endl;
	cout << "Salary Range: " << salaryRange << endl;
	cout << "Median Salary: " << medianSalary << endl;
	cout << "Average Salary for Software Engineers: " << averageSoftwareEngineer << endl;
	cout << "Average Salary for Senior Software Engineers: " << averageSeniorSoftwareEngineer << endl;
	cout << "Average Salary for Data Scientists: " << averageDataScientist << endl;
	cout << "Average Salary for Project Managers: " << averageProjectManager << endl;
	cout << "Average Salary for Senior Data Analysts: " << averageSeniorDataAnalyst << endl;
	cout << "Average Salary for UX Designers: " << averageUXDesigner << endl;
	cout << "Average Salary for QA Analysts: " << averageQAAnalyst << endl;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getSalary() == highestSalary) {
			cout << "Employee with highest salary: " << endl;
			employees[i].print();
		}
	}

	//highest payinf designatio		
	if (averageDataScientist > averageProjectManager && averageDataScientist > averageQAAnalyst && averageDataScientist > averageSeniorDataAnalyst && averageDataScientist > averageSeniorSoftwareEngineer && averageDataScientist > averageSoftwareEngineer && averageDataScientist > averageUXDesigner) {
		cout << "Highest paying designation: Data Scientist" << endl;
	}
	else if (averageProjectManager > averageDataScientist && averageProjectManager > averageQAAnalyst && averageProjectManager > averageSeniorDataAnalyst && averageProjectManager > averageSeniorSoftwareEngineer && averageProjectManager > averageSoftwareEngineer && averageProjectManager > averageUXDesigner) {
		cout << "Highest paying designation: Project Manager" << endl;
	}
	else if (averageQAAnalyst > averageDataScientist && averageQAAnalyst > averageProjectManager && averageQAAnalyst > averageSeniorDataAnalyst && averageQAAnalyst > averageSeniorSoftwareEngineer && averageQAAnalyst > averageSoftwareEngineer && averageQAAnalyst > averageUXDesigner) {
		cout << "Highest paying designation: QA Analyst" << endl;
	}
	else if (averageSeniorDataAnalyst > averageDataScientist && averageSeniorDataAnalyst > averageProjectManager && averageSeniorDataAnalyst > averageQAAnalyst && averageSeniorDataAnalyst > averageSeniorSoftwareEngineer && averageSeniorDataAnalyst > averageSoftwareEngineer && averageSeniorDataAnalyst > averageUXDesigner) {
		cout << "Highest paying designation: Senior Data Analyst" << endl;
	}
	else if (averageSeniorSoftwareEngineer > averageDataScientist && averageSeniorSoftwareEngineer > averageProjectManager && averageSeniorSoftwareEngineer > averageQAAnalyst && averageSeniorSoftwareEngineer > averageSeniorDataAnalyst && averageSeniorSoftwareEngineer > averageSoftwareEngineer && averageSeniorSoftwareEngineer > averageUXDesigner) {
		cout << "Highest paying designation: Senior Software Engineer" << endl;
	}
	else if (averageSoftwareEngineer > averageDataScientist && averageSoftwareEngineer > averageProjectManager && averageSoftwareEngineer > averageQAAnalyst && averageSoftwareEngineer > averageSeniorDataAnalyst && averageSoftwareEngineer > averageSeniorSoftwareEngineer && averageSoftwareEngineer > averageUXDesigner) {
		cout << "Highest paying designation: Software Engineer" << endl;
	}
	else if (averageUXDesigner > averageDataScientist && averageUXDesigner > averageProjectManager && averageUXDesigner > averageQAAnalyst && averageUXDesigner > averageSeniorDataAnalyst && averageUXDesigner > averageSeniorSoftwareEngineer && averageUXDesigner > averageSoftwareEngineer) {
		cout << "Highest paying designation: UX Designer" << endl;
	}
	else {
		cout << "Highest paying designation: Senior Software Engineer" << endl;
	}
}


void tenureAnalysis(Employee* employees) {
	float longestTenure = 0;
	int longestTenureIndex = 0;


	for (int i = 0; i < 10; i++) {
		if (employees[i].getTenure() > longestTenure) {
			longestTenure = employees[i].getTenure();
			longestTenureIndex = i;
		}
	}

	int shortestTenure = 9999999;
	int shortestTenureIndex = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getTenure() < shortestTenure) {
			shortestTenure = employees[i].getTenure();
			shortestTenureIndex = i;
		}
	}


	int numberOfSoftwareEngineers = 0;
	int numberOfSeniorSoftwareEngineers = 0;
	int numberOfDataScientists = 0;
	int numberOfProjectManagers = 0;
	int numberOfSeniorDataAnalysts = 0;
	int numberOfUXDesigners = 0;
	int numberOfQAAnalysts = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getDesignation() == "Software Engineer") {
			numberOfSoftwareEngineers++;
		}
		else if (employees[i].getDesignation() == "Senior Software Engineer") {
			numberOfSeniorSoftwareEngineers++;
		}
		else if (employees[i].getDesignation() == "Data Scientist") {
			numberOfDataScientists++;
		}
		else if (employees[i].getDesignation() == "Project Manager") {
			numberOfProjectManagers++;
		}
		else if (employees[i].getDesignation() == "Senior Data Analyst") {
			numberOfSeniorDataAnalysts++;
		}
		else if (employees[i].getDesignation() == "UX Designer") {
			numberOfUXDesigners++;
		}
		else if (employees[i].getDesignation() == "Quality Assurance Analyst") {
			numberOfQAAnalysts++;
		}
	}

	float totalTenureSoftwareEngineer = 0;
	float totalTenureSeniorSoftwareEngineer = 0;
	float totalTenureDataScientist = 0;
	float totalTenureProjectManager = 0;
	float totalTenureSeniorDataAnalyst = 0;
	float totalTenureUXDesigner = 0;
	float totalTenureQAAnalyst = 0;

	for (int i = 0; i < 10; i++) {
		if (employees[i].getDesignation() == "Software Engineer") {
			totalTenureSoftwareEngineer += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "Senior Software Engineer") {
			totalTenureSeniorSoftwareEngineer += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "Data Scientist") {
			totalTenureDataScientist += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "Project Manager") {
			totalTenureProjectManager += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "Senior Data Analyst") {
			totalTenureSeniorDataAnalyst += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "UX Designer") {
			totalTenureUXDesigner += employees[i].getTenure();
		}
		else if (employees[i].getDesignation() == "Quality Assurance Analyst") {
			totalTenureQAAnalyst += employees[i].getTenure();
		}
	}

	float averageTenureSoftwareEngineer = totalTenureSoftwareEngineer / numberOfSoftwareEngineers;
	float averageTenureSeniorSoftwareEngineer = totalTenureSeniorSoftwareEngineer / numberOfSeniorSoftwareEngineers;
	float averageTenureDataScientist = totalTenureDataScientist / numberOfDataScientists;
	float averageTenureProjectManager = totalTenureProjectManager / numberOfProjectManagers;
	float averageTenureSeniorDataAnalyst = totalTenureSeniorDataAnalyst / numberOfSeniorDataAnalysts;
	float averageTenureUXDesigner = totalTenureUXDesigner / numberOfUXDesigners;
	float averageTenureQAAnalyst = totalTenureQAAnalyst / numberOfQAAnalysts;


	cout << "Empoyee with longest tenture: " << endl; employees[longestTenureIndex].print();
	cout << "Employee with shortest tenure: " << endl; employees[shortestTenureIndex].print();

	cout << "Average tenure for Software Engineers: " << averageTenureSoftwareEngineer << " year(s)" << endl;
	cout << "Average tenure for Senior Software Engineers: " << averageTenureSeniorSoftwareEngineer << " year(s)" << endl;
	cout << "Average tenure for Data Scientists: " << averageTenureDataScientist << " year(s)" << endl;
	cout << "Average tenure for Project Managers: " << averageTenureProjectManager << " year(s)" << endl;
	cout << "Average tenure for Senior Data Analysts: " << averageTenureSeniorDataAnalyst << " year(s)" << endl;
	cout << "Average tenure for UX Designers: " << averageTenureUXDesigner << " year(s)" << endl;
	cout << "Average tenure for QA Analysts: " << averageTenureQAAnalyst << " year(s)" << endl;
}


