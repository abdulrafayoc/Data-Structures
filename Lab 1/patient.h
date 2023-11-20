#pragma once

#include <iostream>
//#include <iostream>
using namespace std;

class Patient {
private:
	string name;
	string type;
	int ndays;
public:
	Patient() {
		name = "";
		ndays = 0;
	}
	Patient(string n, string t, int nd=0) {
		name = n;
		type = t;
		ndays = nd;
	}
	int getDays() {
		return ndays;
	}
	
};