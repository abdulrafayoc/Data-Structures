#pragma once

#include <iostream>

using namespace std;

char* find(string str, char ch) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch) {
			count = i;
			break;
		}
	}
	

	char* result = new char [str.length() - count];
	for (int i = 0; i < str.length()-count ; i++) {
		result[i] = str[i + count];
		cout << result[i];
	}
	return result;
}	