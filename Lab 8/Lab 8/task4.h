#pragma once

#include <iostream>
#include "task1.h"
using namespace std;


class Task {
public:
	int time;
	int id;
};
void robin_bhai() {
	Queue<Task> tasks;
	int num_tasks;
	cout << "Enter number of tasks: ";
	cin >> num_tasks;

	for (int i = 0; i < num_tasks; i++) {
		cout << "enter id for task " << i + 1 << ": ";
		int id;
		cin >> id;
		cout << "Enter time needed to this task: ";
		int time;
		cin >> time;
		Task t;
		t.id = id;
		t.time = time;
		tasks.enqueue(t);

	}

	int quantum;
	cout << "Enter quantum: ";
	cin >> quantum;

	while (!tasks.isEmpty()) {
		Task t = tasks.show_front();
		if (t.time > quantum) {
			t.time -= quantum;
			tasks.dequeue();
			tasks.enqueue(t);
		}
		else {
			tasks.dequeue();
			cout << "Task " << t.id << " is completed" << endl;
		}

	}
}

