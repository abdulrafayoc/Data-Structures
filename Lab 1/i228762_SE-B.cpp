#include <iostream>
#include <string>
#include "hospital.h"
#include "patient.h"

using namespace std;


void inpatientMenu(Hospital &h) {
	string name;
	int ndays;
	double dRate;

	cout << "Enter Name:";
	cin >> name;
	cout << "The number of days spent in the hospital:";
	cin >> ndays;
	/*cout << "The daily rate:";
	cin >> dRate;*/
	cout << "Hospital medication charges:";
	int hCharges;
	int mCharges;
	cin >> mCharges;
	cout << "Charges for hospital services(lab tests, etc):";
	cin >> hCharges;

	Patient p(name, "inpatient", ndays);
	h.in(&p, mCharges, hCharges);


}

void outpatientMenu(Hospital &h) {
	int hCharges;
	int mCharges;
	string name;

	cout << "Enter Name:";
	cin >> name;
	//getline(cin, name);
	//cin.getline(name);
	cout << "Charges for hospital services(lab tests, etc.):";
	cin >> hCharges;
	cout << "Hospital medication charges:";
	cin >> mCharges;

	Patient p(name, "outpatient");
	h.in(&p, mCharges, hCharges);

}


int main() {
	Hospital AlQaida;
	cout << "Patient Type: \n";
	cout << "1- inpatient \n2- outpatient\n";
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		inpatientMenu(AlQaida);
		break;
	case 2:
		outpatientMenu(AlQaida);
		break;

	default:
		break;
	}
	AlQaida.Display();

	return 0;
}