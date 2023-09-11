#include <iostream>
#include "header.h"

using namespace std;

int main() {
	cout << "Enter a String: ";
	string str;
	cin >> str;

	cout << "Enter a character to find: ";
	char ch;
	cin >> ch;

	char* strr =  find(str, ch);




}