#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class DoublyCircularLinkedList {
private:
	Node* head;
public:
	DoublyCircularLinkedList() {
		head = NULL;
	}
	DoublyCircularLinkedList(Node* h) {
		head = h;
	}
	void insertInBeg(int d) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			n->next = head;
			n->prev = head;
		}
		else {
			Node* curr = head->prev;
			curr->next = n;
			n->prev = curr;
			n->next = head;
			head->prev = n;
			head = n;
		}
	}
	void insertInEnd(int d) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			n->next = head;
			n->prev = head;
		}
		else {
			Node* curr = head->prev;
			curr->next = n;
			n->prev = curr;
			n->next = head;
			head->prev = n;
		}
	}
	void insertBefore(int d, int before) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			n->next = head;
			n->prev = head;
		}
		else {
			Node* curr = head;
			while (curr->next != head) {
				if (curr->next->data == before) {
					break;
				}
				curr = curr->next;
			}
			n->next = curr->next;
			curr = n;
			curr->next = n;
			n->prev = curr;
		}
	}
	void insertAfter(int d, int after) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			n->next = head;
			n->prev = head;
		}
		else {
			Node* curr = head;
			while (curr->next != head) {
				if (curr->data == after) {
					break;
				}
				curr = curr->next;
			}
			n->next = curr->next;
			curr = n;
			curr->next = n;
			n->prev = curr;
		}
	}
	void deleteHead() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
		}
	}
	void deleteMiddle() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* curr = head;
			int size = 0;
			while (curr->next != head) {
				size++;
				curr = curr->next;
			}
			int index = size / 2;
			curr = head;
			for (int i = 0; i < index; i++) {
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
	}
	void deleteTail() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* curr = head;
			while (curr->next != head) {
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
	}
	void remove(int d) {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* curr = head;
			while (curr->next != head) {
				if (curr->data == d) {
					break;
				}
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
	}
	void print() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* curr = head;
			while (curr->next != head) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << curr->data << endl;
		}
	}

	void swap(Node* a, Node* b) {
		int temp = a->data;
		a->data = b->data;
		b->data = temp;

	}

	void sort() {
		Node* curr = head;
		Node* temp = NULL;
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			while (curr->next != head) {
				temp = curr->next;
				while (temp != head) {
					if (curr->data > temp->data) {
						swap(curr, temp);
					}
					temp = temp->next;
				}
				curr = curr->next;
			}
		}
	}
	void removeDuplicates() {
		sort();
		Node* curr = head;

		while (curr->next != head) {
			if (curr->data == curr->next->data) {
				remove(curr->data);
			}
			curr = curr->next;
		}
	}


};