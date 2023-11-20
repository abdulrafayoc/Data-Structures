#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main() {
	DoublyCircularLinkedList list;
	list.insertInBeg(40);
	list.insertInEnd(1);
	list.insertInBeg(20);
	list.insertInBeg(50);
	list.insertInBeg(30);
	list.insertInEnd(5);
	list.insertInBeg(10);
	list.insertInBeg(60);

	cout << "Current List: ";
	list.print();
	cout << endl;

	int choice = 0;
	while (1){
	cout << "1. Insert in Beginning" << endl;
	cout << "2. Insert in End" << endl;
	cout << "3. Insert Before" << endl;
	cout << "4. Insert After" << endl;
	cout << "5. Remove" << endl;
	cout << "6. Remove First" << endl;
	cout << "7. Remove Last" << endl;
	cout << "8. Remove Middle" << endl;
	cout << "9. Sort" << endl;
	cout << "10. Print" << endl;


	cout << "Enter Choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		list.insertInBeg(10);
		cout << "10 added to the beginning of the list" << endl;
		break;
	case 2:
		list.insertInEnd(15);
		cout << "15 added to the end of the list" << endl;
		break;
	case 3:
		//list.insertBefore(10, 20);
		cout << "10 added before 20" << endl;
		break;
	case 4:
		//list.insertAfter(10, 20);
		cout << "10 added after 20" << endl;
		break;
	case 5:
		list.remove(10);
		cout << "10 removed from the list" << endl;
		break;
	case 6:
		list.deleteHead();
		cout << "First element removed from the list" << endl;
		break;
	case 7:
		list.deleteTail();
		cout << "Last element removed from the list" << endl;
		break;
	case 8:
		list.deleteMiddle();
		cout << "Middle element removed from the list" << endl;
		break;
	case 9:
		list.sort();
		cout << "List sorted" << endl;
		list.print();
		break;
	case 10:
		list.print();
		break;
	case 11:
		list.removeDuplicates();



	}
	cin >> choice;


}


}