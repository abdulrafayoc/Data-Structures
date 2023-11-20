#pragma once

#include <iostream>
#include <string>
#include "task1.h"
using namespace std;

void heavy_$$$_encriptoooooooor(string pass) {
	Queue<char> num;
	Queue<char> alp;
	Queue<char> art;


	// step 1
	for (int i = 0; i < pass.length(); i++) {
		if (pass[i] >= '0' && pass[i] <= '9') {
			num.enqueue(pass[i]);
		}
		else if ((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z')) {
			alp.enqueue(pass[i]);
		}
		else {
			art.enqueue(pass[i]);
		}
	}

	num.display();
alp.display();
art.display();


	char op = ' ';
	for (int i = 0; i < art.size(); i++) {
		if (art.get(i) == '^') {
			op = art.get(i);
			break;
		}
		else if (art.get(i) == '*' || art.get(i) == '/') {
			op = art.get(i);
			break;
		}
		else if (art.get(i) == '+' || art.get(i) == '-') {
			op = art.get(i);
		}
	}
	cout << op << endl;
	int res = 0;
	if (op == ' ') {
		cout << "this is an" << endl;
		return;
	}
	if (op == '*') {
		res = 1;
		for (int i = 0; i < num.size(); i++) {	
			res *= (num.get(i) - 48);
			
		}
	}
	else if (op == '/') {
		res = num.get(0);
		for (int i = 1; i < num.size(); i++) {
			res /= num.get(i);
		}
	}
	else if (op == '+') {
		res = 0;
		for (int i = 0; i < num.size(); i++) {
			res += num.get(i);
		}
	}
	else if (op == '-') {
		res = num.get(0);
		for (int i = 1; i < num.size(); i++) {
			res -= num.get(i);
		}
	}


	cout << res << endl;

	string result = "";
	for (int i = 0; i < alp.size(); i++) {
		result += alp.get(i);
	}
	result += to_string(res);
	for (int i = 0; i < art.size(); i++) {
		result += art.get(i);
	}

	cout << result << endl;
}