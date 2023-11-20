#include <iostream>
#include <fstream>
#include <string>
#include "Task 1.h"
#include "Task 2.h"
#include "Task 3.h"
using namespace std;

int main() {

	/*fstream file;
	file.open("file.csv");

	Stack<Student> students;

	string line;
	getline(file, line);
	for (int i = 0; i < 30; i++) {
		if (file.eof()) {
			break;
		}
		getline(file, line);
		Student temp;
		temp.set_student(line);
		students.push(temp);
	}*/

	//Task 1
	cout << "Task 1" << endl;
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	cout << stack.peak() << endl;


	//Task 2

	cout << "Task 2" << endl;

	string str = "({))";

	if (isBalanced(str)) {
		cout << "Balanced" << endl;
	}
	else {
		cout << "Not balanced" << endl;
	}

	//Task 3

	cout << "Task 3" << endl;



	return 0;

}