#pragma once

#include <iostream>

using namespace std;


class Employee {
private:
	string name;
	string DOB;
	string department;
	double salary;
public:
	Employee() {
		name = "";
		DOB = "";
		salary = 0;
	}
};

template <class T>
class Node {
public:
	T data;
	Node* next;
Node() {
		
		next = NULL;
	}
};

template <class T>
class Queue{
private:
	Node<T>* front;
	Node<T>* rear;
	int count;
public:
Queue() {
		front = NULL;
		rear = NULL;
		count = 0;
	}
	void enqueue(T data) {
		Node<T>* temp = new Node<T>;
		temp->data = data;
		if (front == NULL) {
			front = temp;
			rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		count++;
	}
	void dequeue() {
		if (front == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			Node<T>* temp = front;
			front = front->next;
			delete temp;
			count--;
		}
	}
	void display() {
		Node<T>* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		if (front == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	T getFront() {
		if (front == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			return front->data;
		}
	}
	T getRear() {
		if (rear == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			return rear->data;
		}
	}
	T get(int index) {
		if (index < 0 || index >= count) {
			cout << "Index out of range" << endl;
		}
		else {
			Node<T>* temp = front;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}
	T show_front() {
		return front->data;
	}
	void remove(T t) {
		Node<T>* temp = front;
		Node<T>* prev = NULL;
		while (temp != NULL) {
			if (temp->data == t) {
				if (prev == NULL) {
					front = front->next;
					delete temp;
					temp = front;
				}
				else {
					prev->next = temp->next;
					delete temp;
					temp = prev->next;
				}
				count--;
			}
			else {
				prev = temp;
				temp = temp->next;
			}
		}
	}
};