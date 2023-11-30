#pragma once
#include <iostream>
#include <string>

using namespace std;
// modifing to weighted graph
class Node {
public:
    int data;
    Node* next;
	int weight;

    Node(int d, int w = 0) : data(d), next(nullptr), weight(w) {}
};



class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addNode(int d, int w = 0) {
        Node* newNode = new Node(d, w);
        newNode->next = head;
        head = newNode;
    }
};

class Graph {
public:
    LinkedList* adjList;
    int numVertices;
public:
    Graph(int numVertices) : numVertices(numVertices) {
		adjList = new LinkedList[numVertices];
	}

	void addEdge(int src, int dest, int weight = 0) {
		adjList[src].addNode(dest, weight);
		adjList[dest].addNode(src, weight);
	}

	void printGraph() {
		for (int i = 0; i < numVertices; i++) {
			Node* temp = adjList[i].head;
			cout << "Vertex " << i << " is linked to: ";
			while (temp) {
				cout << "Vertex " << temp->data << " (" << temp->weight << ") ,";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};