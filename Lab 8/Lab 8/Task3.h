#pragma once
#include <iostream>
#include <string>
#include "task1.h"

using namespace std;

// to implement a stack using multiple queues.
class Stack
{
private:
Queue<int> q1, q2;
public:
	Stack() {

}
~Stack() {

}
	void push(int value) {
		q1.enqueue(value);
	}
	void pop() {
		while (q1.size() > 1) {
			q2.enqueue(q1.show_front());
			q1.dequeue();
		}
		q1.dequeue();
		while (!q2.isEmpty()) {
			q1.enqueue(q2.show_front());
			q2.dequeue();
		}
	}
	int top() {
		while (q1.size() > 1) {
			q2.enqueue(q1.show_front());
			q1.dequeue();
		}
		int value = q1.show_front();
		q2.enqueue(value);
		q1.dequeue();
		while (!q2.isEmpty()) {
			q1.enqueue(q2.show_front());
			q2.dequeue();
		}
		return value;
	}
	void pop(int n) {
		cout << n << endl;
	}

	

};
