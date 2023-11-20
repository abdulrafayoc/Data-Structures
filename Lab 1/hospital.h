#pragma once

#include <iostream>
#include "patient.h"
using namespace std;

class Hospital {
private:
	Patient *p;
	double dRate;
	int mCharges;
	int hCharges;
public:
	Hospital() {
		mCharges = 0;
		dRate = 1000;
		hCharges = 0;
	}
	Hospital(Patient *pp ,int  mC, int hC ) {
		/*p = pp;
		mCharges += mC;
		dRate += dRate * pp->getDays();
		hCharges += hC;*/
	}
	void in(Patient* pp, int  mC, int hC) {
		p = pp;
		mCharges += mC;
		dRate = dRate * pp->getDays();
		hCharges += hC;
	}
	void Display() {
		cout << "Daily Rate = " << 1000 << endl;
		cout << "Stay Charges = " << dRate << endl;
		cout << "Meditaion Charges = " << mCharges << endl;
		cout << "Hospital Charges = " << hCharges << endl;
	}
};