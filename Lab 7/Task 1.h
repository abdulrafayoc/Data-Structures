#pragma once

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node() {
		next = NULL;
	}
	Node(T x) {
		data = x;
		next = NULL;
	}
	~Node() {
		delete next;
	}
};

template <class T>
class Stack {
private:
	Node<T>* top;
public:
	Stack() {
		top = NULL;
	}
	void push(T x) {
		Node<T>* t = new Node<T>;
		if (t == NULL)
			cout << "Stack is full\n";
		else {
			t->data = x;
			t->next = top;
			top = t;
		}
	}
	T pop() {
		T x = -1;
		if (top == NULL)
			cout << "Stack is empty\n";
		else {
			x = top->data;
			Node<T>* t = top;
			top = top->next;
			delete t;
		}
		return x;
	}
	void Display() {
		Node* p = top;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	T peak() {
		return top->data;
	}
	T isEmpty() {
		return !top;
	}

};