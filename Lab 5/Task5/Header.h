#pragma once

#include <iostream>

using namespace std;

class Employee {
	int id;
	string nic;
	double salary;
	double bonus;
public:
	Employee() {
		id = 0;
		nic = "";
		salary = 0;
		bonus = 0;
	}
	Employee(int id, string nic, double salary, double bonus) {
		this->id = id;
		this->nic = nic;
		this->salary = salary;
		this->bonus = bonus;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	void setBonus(double bonus) {
		this->bonus = bonus;
	}
	int getID() {
		return id;
	}
	string getNIC() {
		return nic;
	}
	double getSalary() {
		return salary;
	}
	double getBonus() {
		return bonus;
	}

	void print() {
		cout << "-------" << endl;
		cout << "ID: " << id << endl;
		cout << "NIC: " << nic << endl;
		cout << "Salary: " << salary << endl;
		cout << "Bonus: " << bonus << endl;
	}

};

class Node {
public:
	Employee* data;
	Node* next;
};


class LinkedList {
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void add(Employee* data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}
	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}
	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
	void insert(const Employee& emp) {
		if (head == nullptr) {
			head = new Node();
			head->data = new Employee(emp);
			head->next = nullptr;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = new Node();
			current->next->data = new Employee(emp);
			current->next->next = nullptr;
		}
	}

	void remove(int id) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = head;
			if (current->data->getID() == id) {
				head = current->next;
				delete current;
			}
			else {
				Node* previous = nullptr;
				while (current != nullptr) {
					if (current->data->getID() == id) {
						previous->next = current->next;
						delete current;
						break;
					}
					previous = current;
					current = current->next;
				}
			}
		}
	}

	void UpdateSalary(const int& salary, int id) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = head;
			while (current != nullptr) {
				if (current->data->getID() == id) {
					current->data->setSalary(salary);
					break;
				}
				current = current->next;
			}
		}
	}
	void UpdateBonus(const int& bonus, int id) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = head;
			while (current != nullptr) {
				if (current->data->getID() == id) {
					current->data->setBonus(bonus);
					break;
				}
				current = current->next;
			}
		}
	}
	void clear() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void display() {
		Node* current = head;
		while (current != nullptr) {
			cout << "ID: " << current->data->getID() << endl;
			cout << "NIC: " << current->data->getNIC() << endl;
			cout << "Salary: " << current->data->getSalary() << endl;
			cout << "Bonus: " << current->data->getBonus() << endl;
			current = current->next;
		}
		cout << endl;
	}
	void sort() {
		Node* current = head;
		Node* index = nullptr;

		if (head == nullptr) {
			cout << "List is empty" << endl;

		}
		else {
			while (current != nullptr) {
				index = current->next;
				while (index != nullptr) {
					if (current->data->getSalary() > index->data->getSalary()) {
						Node* temp = new Node();
						temp->data = current->data;
						current->data = index->data;
						index->data = temp->data;
					}
					index = index->next;
				}
				current = current->next;
			}
		}
	}
};

