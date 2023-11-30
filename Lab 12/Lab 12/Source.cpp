#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void prefixSearch(AVLTree<string>& tree) {
	string prefix;
	cout << "Type: ";
	cin >> prefix;

	Node<string>* temp = tree.root;

	while (temp != NULL) {
		if (temp->data.substr(0, prefix.length()) == prefix) {
			cout << temp->data << " Occurance : " << temp->count << endl;
		}
		if (temp->data.substr(0, prefix.length()) < prefix) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
}

void deleteWord(AVLTree<string>& tree) {
	string word;
	cout << "Enter a word to delete: ";
	cin >> word;

	tree.remove(word);
}

void import(AVLTree<string>& tree) {
	ifstream file("data.txt");
	string word;
	while (file >> word) {
		tree.insert(word);
	}

	
}


int main() {

	AVLTree<string> tree;
	cout << "***** Lab 12 *****" << endl << endl;
	cout << "Menu: " << endl;
	cout << "1. Load Dictionary" << endl;
	cout << "2. Autocomplete" << endl;
	cout << "3. Delete Word" << endl;
	cout << "4. Exit" << endl;

	cout << endl;

	int choice;
	do {
		cout << "Enter a choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			import(tree);
			cout << "Dictionary Loaded." << endl;
			break;
		case 2:
			prefixSearch(tree);
			break;
		case 3:
			deleteWord(tree);
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
	} while (choice != 4);


	tree.print();
	cout << endl;





}

