#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

void mainMenu(Tree tree) {
	while (1) {
		cout << endl;
		cout << "1. Create directory" << endl;
		cout << "2. Create file" << endl;

		cout << "3. Delete file" << endl;

		cout << "4. Merge Directories" << endl;
		cout << "5. Rename" << endl;

		cout << "6. Search" << endl;
		cout << "7. Copy or Move" << endl;
		cout << "8. Export OR Import" << endl;
		cout << "9. Print tree" << endl;
		cout << "0. Exit" << endl;

		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		cout << endl << endl;
		string str;
		string strrr;
		string strr;
		switch (choice) {
		case 1:
			cout << "Enter name of directory: ";
			cin >> str;
			cout << "Enter Parent directory path: ";
			cin >> strrr;

			tree.fixPaths();
			createDirectory(*tree.findNode(strrr), str);
			break;
		case 2:
			cout << "Enter name of file: ";
			cin >> str;
			cout << "Enter type of file: ";
			cin >> strr;
			cout << "Enter Parent directory path: ";
			cin >> strrr;

			tree.fixPaths();
			createFile(*tree.findNode(strrr), str + "." + strr);
			break;
		case 3:
			cout << "Enter path of file or directory: ";
			cin >> str;
			deleteNode(*tree.findNode(str), tree);
			break;
		case 4:
			cout << "Enter name of source directory: ";
			cin >> str;
			cout << "Enter name of destination directory: ";
			cin >> strr;
			mergeDirectories(*tree.findNodeByName(str), *tree.findNodeByName(strr));
			break;
		case 5:
			cout << "Enter name of file or directory: ";
			cin >> str;
			cout << "Enter new name: ";
			cin >> strr;
			rename(*tree.findNodeByName(str), strr);
			break;
		case 6:
			cout << "Enter name of file or directory: ";
			cin >> str;
			display(*tree.findNodeByName(str));
			break;

		case 7:
			cout << "1. Copy" << endl;
			cout << "2. Move" << endl;

			cout << "Enter your choice: ";
			cin >> choice;

			cout << endl << endl;
			if (choice == 1) {


				cout << "Enter name of file or directory: ";
				cin >> str;
				cout << "Enter destination directory: ";
				cin >> strr;
				copy(*tree.findNodeByName(str), *tree.findNodeByName(strr));
			}
			else if (choice == 2) {
				cout << "Enter name of file or directory: ";
				cin >> str;
				cout << "Enter destination directory: ";
				cin >> strr;
				move(*tree.findNodeByName(str), *tree.findNodeByName(strr), tree);
			}
			else {
				cout << "Wrong choice" << endl;
			}

			break;
		case 8:
			cout << "1. Export" << endl;
			cout << "2. Import" << endl;

			cout << "Enter your choice: ";
			cin >> choice;

			cout << endl << endl;

			if (choice == 1) {
				exportData(tree);
				cout << "Data exported successfully" << endl;
			}
			else if (choice == 2) {
				importData(*tree.getRoot());
			}
			else {
				cout << "Wrong choice" << endl;
			}

			exportData(tree);
			break;
		case 9:
			tree.print_tree();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}

}

int main() {
	Tree tree = Tree(Node("root", "root/", true));

	createDirectory(*tree.getRoot(), "logs");
	createDirectory(*tree.getRoot(), "pat");

	createDirectory(*tree.getRoot()->left, "can");
	createDirectory(*tree.getRoot()->right, "ali");

	mainMenu(tree);

	tree.print_tree();
	cout << endl;

}