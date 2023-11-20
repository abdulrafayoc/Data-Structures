#include <iostream>
#include "Header.h"
using namespace std;
int main() {

	Tree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(11);
	tree.insert(12);
	tree.insert(20);
	tree.insert(30);
	tree.insert(50);

	cout << "Tree:";
	tree.print();

	while (true)
	{
		int choice;
		cout << "Huzaifa Mahmood _ 22i-2669" << endl;
		cout << endl << endl;
		cout << "1- Height" << endl;
		cout << "2- Depth" << endl;
		cout << "3- Count in range" << endl;
		cout << "4- Kth smallest" << endl;

		cout << "Enter choice: ";
		cin >> choice;

		int temp;
		int a, b;
		switch (choice)
		{
		case 1:
			cout << "Height: ";
			cout << tree.height();
			break;
		case 2:
			cout << "Enter the number you want to find the depth of: ";
			cin >> temp;
			cout << "Depth: ";
			cout << tree.depth(temp);
			break;
		case 3:
			cout << "Enter the range: ";
			cin >> a >> b;
			cout << "No of nodes between " << a << " and " << b << ": ";
			cout << tree.countInRange(a, b);
			break;
		case 4:
			cout << "Enter the kth smallest number you want to find: ";
			cin >> temp;
			cout << "Kth smallest: ";
			cout << tree.kthSmallest(temp);
			break;
		}
	}
	cout << endl << endl;


	return 0;
}