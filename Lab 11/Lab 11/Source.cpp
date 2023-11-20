#include <iostream>
#include "Header.h"	
#include <string>

using namespace std;

int main() {
	AVLTree tree;
	tree.insert(5);
	tree.insert(6);
	tree.insert(50);
	tree.insert(40);
	tree.insert(-1);
	tree.print();
	cout << endl << " ------------- " << endl;
	
	tree.printHeightsofnodes();

	cout << endl << " height of tree " << tree.height() << endl;
}