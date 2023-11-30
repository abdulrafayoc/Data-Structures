#include "Header.h"
#include <iostream>

using namespace std;

int main() {
	
	cout << "Enter the number of vertices: ";
	int numVertices;
	cin >> numVertices;
	Graph g(numVertices);
	 
	// menu
	while (1) {
		cout << "1. Add edge" << endl;
		cout << "2. Print graph" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Enter source and destination: ";
			int src, dest;
			cin >> src >> dest;
			cout << "Enter weight: ";
			int weight;
			cin >> weight;
			g.addEdge(src, dest, weight);
			break;
		}
		case 2: {
			g.printGraph();
			break;
		}
		case 3: {
			exit(0);
		}
		default: {
			cout << "Invalid choice" << endl;
		}
		}
	}

	g.printGraph();

	return 0;
}