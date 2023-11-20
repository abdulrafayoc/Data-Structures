#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Student {
private:
	string reg_dt;
	string roll_no;
	string name;
	string marks[8];
	string abs[5];
	string grand_tot;
	string grade;
public:
	Student() {
		reg_dt = "";
		roll_no = "";
		for (int i = 0; i < 8; i++) {
			marks[i] = "0";
		}
		for (int i = 0; i < 4; i++) {
			abs[i] = "0";
		}
		grade = "";
	}
	void set_student(string line)
	{

	}
	
	string get_reg_dt() {
		return reg_dt;
	}
	void set_reg_dt(string reg_dt) {
		this->reg_dt = reg_dt;
	}
	string get_roll_no() {
		return roll_no;
	}
	void set_roll_no(string roll_no) {
		this->roll_no = roll_no;
	}
	string get_marks(int i) {
		return marks[i];
	}
	void set_marks(int i, string marks) {
		this->marks[i] = marks;
	}
	string get_abs(int i) {
		return abs[i];
	}
	void set_abs(int i, string abs) {
		this->abs[i] = abs;
	}
	string get_grade() {
		return grade;
	}
	void set_grade(string grade) {
		this->grade = grade;
	}

	void display() {
		cout << "RegDt.:" << reg_dt << endl;
		cout << "RollNo:" << roll_no << endl;
		cout << "Name:" << name << endl;
		cout << "As:1:" << marks[0] << endl;
		cout << "As:2:" << marks[1] << endl;
		cout << "As:3:" << marks[2] << endl;
		cout << "As:4:" << marks[3] << endl;
		cout << "As:" << abs[0] << endl;
		cout << "S-I:1:" << marks[4] << endl;
		cout << "S-I:" << abs[1] << endl;
		cout << "Proj:1:" << marks[5] << endl;
		cout << "Proj:" << abs[2] << endl;
		cout << "Final:1:" << marks[6] << endl;
		cout << "Final:" << abs[3] << endl;
		cout << "Mid:1:" << marks[7] << endl;
		cout << "Mid:" << abs[4] << endl;
		cout << "G.Tot:" << grand_tot << endl;
		cout << "Grade:" << grade << endl;
		cout << endl;
	}

};


void sort_by_Roll(Student s[]) {
	
}