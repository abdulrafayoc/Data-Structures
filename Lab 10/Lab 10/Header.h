#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* right;

};

class Tree {
public:
	Node<int>* root;
	Tree() {
		root = NULL;

	}
	~Tree() {
		delete root;
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
	}

	void print() {
		print(root);
	}
	void print(Node<int>* node) {
		if (node == NULL) {
			return;
		}
		print(node->left);
		cout << node->data << " / ";
		print(node->right);
	}
	
	int height() {
		return height(root);
	}
int height(Node<int>* node) {
		if (node == NULL) {
			return 0;
		}
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}


	int depth(int data) {
		return depth(root, data);
	}
	int depth(Node<int>* node, int data) {
		if (node == NULL) {
			return 0;
		}
		if (node->data == data) {
			return 1;
		}
		int leftDepth = depth(node->left, data);
		int rightDepth = depth(node->right, data);
		if (leftDepth > rightDepth) {
			return leftDepth + 1;
		}
		else {
			return rightDepth + 1;
		}
	}

int countInRange(int L, int R) {
		return countInRange(root, L, R);
	}
	int countInRange(Node<int>* node, int L, int R) {
		if (node == NULL) {
			return 0;
		}
		if (node->data >= L && node->data <= R) {
			return 1 + countInRange(node->left, L, R) + countInRange(node->right, L, R);
		}
		else if (node->data < L) {
			return countInRange(node->right, L, R);
		}
		else {
			return countInRange(node->left, L, R);
		}
	}


	int kthSmallest(int k) {
		return kthSmallest(root, k);
	}
	int kthSmallest(Node<int>* node, int k) {
		if (node == NULL) {
			return 0;
		}
		int leftCount = count(node->left);
		if (leftCount == k - 1) {
			return node->data;
		}
		else if (leftCount > k - 1) {
			return kthSmallest(node->left, k);
		}
		else {
			return kthSmallest(node->right, k - leftCount - 1);
		}
	}
	int count(Node<int>* node) {
		if (node == NULL) {
			return 0;
		}
		return 1 + count(node->left) + count(node->right);
	}

};

