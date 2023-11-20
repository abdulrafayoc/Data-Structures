#pragma once

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* right;
	int height;
};

class AVLTree {
public:
	Node<int>* root;
	AVLTree() {
		root = NULL;
	}
	~AVLTree() {
		delete root;
	}
	int height(Node<int>* node) {
		if (node == NULL) {
			return 0;
		}
		return node->height;
	}
	void LR(Node<int>*& node) {
		Node<int>* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		node = temp;
	}
	void RR(Node<int>*& node) {
		Node<int>* temp = node->left;
		node->left = temp->right;
		temp->right = node;
		node = temp;
	}
	void LRR(Node<int>*& node) {
		LR(node->left);
		RR(node);
	}
	void RLR(Node<int>*& node) {
		RR(node->right);
		LR(node);
	}
	void insert(int data) {
		Node<int>* newNode = new Node<int>;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		if (root == NULL) {
			root = newNode;
		}
		else {
			Node<int>* temp = root;
			while (temp != NULL) {
				if (data < temp->data) {
					if (temp->left == NULL) {
						temp->left = newNode;
						break;
					}
					else {
						temp = temp->left;
					}
				}
				else {
					if (temp->right == NULL) {
						temp->right = newNode;
						break;
					}
					else {
						temp = temp->right;
					}
				}
			}
		}
		fixAllHeights();
		balance(root);
	}
	void remove(int data) {
		Node<int>* temp = root;
		Node<int>* parent = NULL;
		while (temp != NULL) {
			if (data < temp->data) {
				parent = temp;
				temp = temp->left;
			}
			else if (data > temp->data) {
				parent = temp;
				temp = temp->right;
			}
			else {
				break;
			}
		}
		if (temp == NULL) {
			return;
		}
		if (temp->left == NULL && temp->right == NULL) {
			if (parent == NULL) {
				root = NULL;
			}
			else if (parent->left == temp) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
			delete temp;
		}
		else if (temp->left == NULL) {
			if (parent == NULL) {
				root = temp->right;
			}
			else if (parent->left == temp) {
				parent->left = temp->right;
			}
			else {
				parent->right = temp->right;
			}
			delete temp;
		}
		else if (temp->right == NULL) {
			if (parent == NULL) {
				root = temp->left;
			}
			else if (parent->left == temp) {
				parent->left = temp->left;

			}
			else {
				parent->right = temp->left;
			}
			delete temp;
		}
		else {
			Node<int>* min = temp->right;
			Node<int>* minParent = temp;
			while (min->left != NULL) {
				minParent = min;
				min = min->left;
			}
			temp->data = min->data;
			if (minParent->left == min) {
				minParent->left = min->right;
			}
			else {
				minParent->right = min->right;
			}
			delete min;
		}
		fixAllHeights();
		balance(root);
	}

	void print() {
		print(root);
	}
	void print(Node<int>* node) {
		if (node == NULL) {
			return;
		}
		print(node->left);
		cout << node->data << "  ";
		print(node->right);
	}
	int height() {
		return height(root);
	}
	void fixAllHeights() {
		fixAllHeights(root);
	}
	void fixAllHeights(Node<int>* node) {
		if (node == NULL) {
			return;
		}
		fixAllHeights(node->left);
		fixAllHeights(node->right);
		node->height = fixHeight(node);
	}
	int fixHeight(Node<int>* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		return (hl > hr ? hl : hr) + 1;
	}
	void balance(Node<int>*& node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hr - hl == 2) {
			if (height(node->right->right) > height(node->right->left)) {
				LR(node);
			}
			else {
				RLR(node);
			}
		}
		else if (hl - hr == 2) {
			if (height(node->left->left) > height(node->left->right)) {
				RR(node);
			}
			else {
				LRR(node);
			}
		}
		node->height = fixHeight(node);
	}

	void printHeightsofnodes() {
		printHeightsofnodes(root);
	}
	void printHeightsofnodes(Node<int>* node) {
		if (node == NULL) {
			return;
		}
		printHeightsofnodes(node->left);
		cout << node->height << "  ";
		printHeightsofnodes(node->right);
	}
};