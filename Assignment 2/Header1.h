#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include "Header.h"

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

};

class intLinkedList {
private:
	Node<int>* head;
	Node<int>* tail;
	int size;
public:
	intLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	intLinkedList(int data) {
		head = new Node<int>;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		size = 1;

	}
	// copy constructor
	intLinkedList(intLinkedList& list) {
		if (list.head == NULL) {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		else {
			Node<int>* temp = list.head;
			while (temp != NULL) {
				add(temp->data);
				temp = temp->next;
			}
		}
	}
	void add(int data) {
		if (head == NULL) {
			head = new Node<int>;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			size = 1;
		}
		else {
			Node<int>* temp = new Node<int>;
			temp->data = data;
			temp->next = NULL;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	int find(int id) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node<int>* temp = head;
			while (temp != NULL) {
				if (temp->data == id) {
					return temp->data;
				}
				temp = temp->next;
			}
			cout << "There is no such element!" << endl;
		}
	}
	bool if_exist(int id) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
			return false;
		}
		else {
			Node<int>* temp = head;
			while (temp != NULL) {
				if (temp->data == id) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
	}
	void delete_node(int id) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node<int>* temp = head;
			while (temp != NULL) {
				if (temp->data == id) {
					if (temp == head) {
						head = head->next;
						head->prev = NULL;
						delete temp;
						size--;
						break;
					}
					else if (temp == tail) {
						tail = tail->prev;
						tail->next = NULL;
						delete temp;
						size--;
						break;
					}
					else {
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
						size--;
						break;
					}
				}
				temp = temp->next;
			}
		}
	}
	int get_size() {
		return size;
	}
	Node<int>* get_head() {
		return head;
	}
	Node<int>* get_tail() {
		return tail;
	}
	int get(int index) {
		if (index < 0 || index >= size)
			return NULL;
		else {
			Node<int>* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}
	void set(int index, int data) {
		if (index < 0 || index >= size)
			return;
		else {
			Node<int>* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			temp->data = data;
		}
	}
};

template <class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	LinkedList(T data) {
		head = new Node<T>;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		size = 1;

	}
	// copy constructor
	LinkedList(LinkedList<T>& list) {
		if (list.head == NULL) {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		else {
			Node<T>* temp = list.head;
			while (temp != NULL) {
				add(temp->data);
				temp = temp->next;
			}
		}
	}
	void add(T data) {
		if (head == NULL) {
			head = new Node<T>;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			size = 1;
		}
		else {
			Node<T>* temp = new Node<T>;
			temp->data = data;
			temp->next = NULL;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	T* find(int id) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node<T>* temp = head;
			while (temp != NULL) {
				if (temp->data.get_id() == id) {
					return &temp->data;
				}
				temp = temp->next;
			}
			cout << "There is no such element!" << endl;
		}
	}
	bool if_exist(int id) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
			return false;
		}
		else {
			Node<T>* temp = head;
			while (temp != NULL) {
				if (temp->data.get_id() == id) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
	}

	void remove(T data) {
		if (head == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node<T>* temp = head;
			while (temp != NULL) {
				if (temp->data == data) {
					if (temp == head) {
						head = head->next;
						head->prev = NULL;
						delete temp;
						size--;
						break;
					}
					else if (temp == tail) {
						tail = tail->prev;
						tail->next = NULL;
						delete temp;
						size--;
						break;
					}
					else {
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
						size--;
						break;
					}
				}
				temp = temp->next;
			}
		}
	}
	void print() {
		if (head == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node<T>* temp = head;
			while (temp != NULL) {
				temp->data.print();
				temp = temp->next;
			}
		}
	}
	int get_size() {
		return size;
	}
	Node<T>* get_head() {
		return head;
	}
	Node<T>* get_tail() {
		return tail;
	}
	T get(int index) {
		if (index < 0 || index >= size)
			return NULL;
		else {
			Node<T>* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}
	void set(int index, T data) {
		if (index < 0 || index >= size)
			return;
		else {
			Node<T>* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			temp->data = data;
		}
	}
	void insert(int index, T data) {
		if (index < 0 || index >= size)
			return;
		else {
			Node<T>* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			Node<T>* new_node = new Node<T>;
			new_node->data = data;
			new_node->next = temp;
			new_node->prev = temp->prev;
			temp->prev->next = new_node;
			temp->prev = new_node;
			size++;
		}
	}



};