#include <iostream>
#include "Header.h"
using namespace std;


int main() {
	int id;
	string nic;
	double salary;
	double bonus;

	cout << "Enter ID, NIC, Salary, Bonus: ";
	cin >> id;
	cin >> nic;
	cin >> salary;
	cin >> bonus;
	Employee E1(id, nic, salary, bonus);

	cout << "Enter ID, NIC, Salary, Bonus: ";
	cin >> id;
	cin >> nic;
	cin >> salary;
	cin >> bonus;
	Employee E2(id, nic, salary, bonus);

	cout << "Enter ID, NIC, Salary, Bonus: ";
	cin >> id;
	cin >> nic;
	cin >> salary;
	cin >> bonus;
	Employee E3(id, nic, salary, bonus);

	LinkedList list;

	list.insert(E1);
	cout << "E1 Added!" << endl;
	list.insert(E2);
	cout << "E2 Added!" << endl;
	list.insert(E3);
	cout << "E3 Added!" << endl;

	cout << endl;
	cout << "All Employees:" << endl;
	list.display();
	list.remove(2);
	cout << endl;
	cout << "Employee id 2 Removed" << endl;
	cout << endl;
	cout << "All Employees:" << endl;
	list.display();
	list.UpdateSalary(200, 3);
	cout << "Salary Updated of Employee id 3!" << endl;
	list.UpdateBonus(150, 1);
	cout << "Bonus Updated of Employee id 1!" << endl;
	cout << endl;
	cout << "All Employees:" << endl;
	list.display();
	cout << "List Empty Status" << list.isEmpty();
	cout << endl;
	list.sort();
	cout << "List Sorted!" << endl;
	cout << endl;
	cout << "All Employees:" << endl;
	list.display();
	return 0;
}