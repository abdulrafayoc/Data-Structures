#pragma once

#include <iostream>
		
#include <string>
#include "Task 1.h"
using namespace std;

bool isBalanced(string str) {
	Stack<char> stack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			stack.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			
			if (stack.isEmpty()) {
				return false;
			}
			else if (str[i] == ')' && stack.peak() == '(') {
				stack.pop();
			}
			else if (str[i] == '}' && stack.peak() == '{') {
				stack.pop();
			}
			else if (str[i] == ']' && stack.peak() == '[') {
				stack.pop();
			}
			else {
				return false;
			}
		}
	}
	return stack.isEmpty();
}	












