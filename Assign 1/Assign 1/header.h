#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Employee {
private:
	string name;
	string ID;
	int salary;
	string dateOfJoining;
	string designation;
public:
	/*static */int size;
	Employee() {
		name = "";
		ID = "";
		salary = 0;
		dateOfJoining = "";
		designation = "";
		size++;
	}
	Employee(string name, string ID, int salary, string dateOfJoining, string designation) {
		this->name = name;
		this->ID = ID;
		this->salary = salary;
		this->dateOfJoining = dateOfJoining;
		this->designation = designation;
	}
	string getName() {
		return name;
	}
	string getID() {
		return ID;
	}
	int getSalary() {
		return salary;
	}
	string getDateOfJoining() {
		return dateOfJoining;
	}
	string getDesignation() {
		return designation;
	}
	void setName(string name) {
		this->name = name;
	}
	void setID(string ID) {
		this->ID = ID;
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
	void setDateOfJoining(string dateOfJoining) {
		this->dateOfJoining = dateOfJoining;
	}
	void setDesignation(string designation) {
		this->designation = designation;
	}
	float getTenure() {
		int year = stoi(dateOfJoining.substr(0, 4));
		int month = stoi(dateOfJoining.substr(5, 2));
		int day = stoi(dateOfJoining.substr(8, 2));

		int currentYear = 2023;
		int currentMonth = 9;
		int currentDay = 10;
		
		int yearDiff = currentYear - year;
		int monthDiff = currentMonth - month;
		int dayDiff = currentDay - day;

		return yearDiff + (monthDiff / 12.0) + (dayDiff / 365.0);
	}
	void print() {
		cout << "\tEmployee Name: " << name << endl;
		cout << "\tEmployee ID: " << ID << endl;
		cout << "\tEmployee Salary: " << salary << endl;
		cout << "\tEmployee Date of Joining: " << dateOfJoining << endl;
		cout << "\tDesignation: " << designation << endl;
		cout << "\tEmployee Tenure: " << getTenure() << " years" << endl;
	}
};

//int Employee::size = 0;