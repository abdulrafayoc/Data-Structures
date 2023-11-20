#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Node {
public:
	string name;
	string path;
	bool is_dir;
	Node* left;
	Node* right;
public:
	Node() {
		name = "";
		path = "";
		is_dir = false;
		left = NULL;
		right = NULL;
	}
	Node(string name, string path, bool is_dir) {
		this->name = name;
		this->path = path;
		this->is_dir = is_dir;
		left = NULL;
		right = NULL;
	}
	Node(string name, bool is_dir) {
		this->name = name;
		this->path = "";
		this->is_dir = "";
		left = NULL;
		right = NULL;
	}
	void addChild(Node* child) {
		if (child->name == "") {
			cout << "Empty node" << endl;
			return;
		}
		if (left == NULL) {
			left = child;
		}
		else if (right == NULL) {
			right = child;
		}
		else {
			cout << "No Space in drectory is full" << endl;
		}

		fixPaths();

	}
	void fixPaths() {
		if (left != NULL) {
			left->path = path + left->name + "/";
		}
		if (right != NULL) {
			right->path = path + right->name + "/";
		}
	}


};


class Tree {
private:
	Node root;
public:
	Tree(Node root) {
		this->root = root;
		root.path = "root/";
	}
	Node* getRoot() {
		return &root;
	}
	void setRoot(Node root) {
		this->root = root;
	}
	void addChild(Node* parent, Node* child) {
		parent->addChild(child);
	}
	void addChild(Node* parent, string name, string path, bool is_dir) {
		Node* child = new Node(name, path, is_dir);
		parent->addChild(child);
	}
	void print_tree(Node* root, int level) {
		if (root->name == "") {
			cout << "Empty tree" << endl;
			return;
		}
		for (int i = 0; i < level; i++) {
			cout << "    ";
		}
		cout << root->name << endl;
		if (root->left != NULL) {
			print_tree(root->left, level + 1);
		}
		if (root->right != NULL) {
			print_tree(root->right, level + 1);
		}
	}
	void print_tree() {
		print_tree(&root, 0);
	}
	void fixPaths(Node* root) {
		if (root->name == "") {
			cout << "Empty tree" << endl;
			return;
		}
		if (root->left != NULL) {
			root->left->path = root->path + root->left->name + "/";
			fixPaths(root->left);
		}
		if (root->right != NULL) {
			root->right->path = root->path + root->right->name + "/";
			fixPaths(root->right);
		}
	}
	void fixPaths() {
		fixPaths(&root);
	}
	Node* findNode(Node* root, string path) {
		if (root->name == "") {
			cout << "Empty tree" << endl;
			return NULL;
		}
		if (root->path == path) {
			return root;
		}
		if (root->left != NULL) {
			Node* temp = findNode(root->left, path);
			if (temp != NULL) {
				return temp;
			}
		}
		if (root->right != NULL) {
			Node* temp = findNode(root->right, path);
			if (temp != NULL) {
				return temp;
			}
		}
		return NULL;
	}
	Node* findNode(string path) {
		return findNode(&root, path);
	}

	Node* findNodeByName(Node* root, string name) {
		if (root->name == "") {
			cout << "Empty tree" << endl;
			return NULL;
		}
		if (root->name == name) {
			return root;
		}
		if (root->left != NULL) {
			Node* temp = findNodeByName(root->left, name);
			if (temp != NULL) {
				return temp;
			}
		}
		if (root->right != NULL) {
			Node* temp = findNodeByName(root->right, name);
			if (temp != NULL) {
				return temp;
			}
		}
		return NULL;

	}
	Node* findNodeByName(string name) {
		return findNodeByName(&root, name);
	}




};
void createDirectory(Node& parent, string name) {
	if (parent.name == "") {
		cout << "No Path Exists!" << endl;
		return;
	}
	Node* child = new Node(name, true);
	parent.addChild(child);
	parent.fixPaths();

}

void createFile(Node& parent, string name) {
	if (parent.name == "") {
		cout << "No Path Exists!" << endl;
		return;
	}
	Node* child = new Node(name, false);
	parent.addChild(child);
	parent.fixPaths();

}

void deleteNode(Node& node, Tree& tree) { // and also remove node from parent

	if (node.name == "") {
		cout << "Empty!" << endl;
		return;
	}
	if (node.path == "root/") {
		cout << "Can't delete root!" << endl;
		return;
	}
	string prntPath = node.path.substr(0, node.name.size() + 1);
	Node* parent = tree.findNode(prntPath);
	if (parent == NULL) {
		cout << "Error" << endl;
		return;
	}

	if (parent->left == &node) {
		parent->left = NULL;
	}
	else if (parent->right == &node) {
		parent->right = NULL;
	}
	else {
		cout << "Error" << endl;
		return;
	}
	delete& node;
}

void mergeDirectories(Node& source, Node& destination) {
	if (source.name == "" || destination.name == "") {
		cout << "Empty!" << endl;
		return;
	}
	if (source.is_dir == false || destination.is_dir == false) {
		cout << "Not a Directory! Failed!" << endl;
		return;
	}
	if (source.left == NULL && source.right == NULL) {
		cout << "Nothing to merge" << endl;
		return;
	}
	if (destination.left != NULL && destination.right != NULL) {
		cout << "Destination already full!" << endl;
		return;
	}

	int count = 0;
	if (source.left != NULL) {
		count++;
	}
	if (source.right != NULL) {
		count++;
	}
	if (destination.left != NULL) {
		count++;
	}
	if (destination.right != NULL) {
		count++;
	}

	if (count > 2) {
		cout << "directories can't be merged (more than 2)" << endl;
		return;
	}

	cout << "Merging Directories..." << endl;
	if (destination.left == NULL) {
		destination.addChild(source.left);
		source.left = NULL;
	}
	cout << "Merging Directories..." << endl;
	if (destination.right == NULL) {
		destination.addChild(source.right);
		source.left = NULL;
	}
	else {
		cout << "No Space in drectory is full" << endl;
	}

}

void rename(Node& node, string name) {
	node.name = name;
	node.fixPaths();
}

void print_dir(Node* root, int level) {
	if (root->name == "") {
		cout << "directory is Empty" << endl;
		return;
	}
	for (int i = 0; i < level; i++) {
		cout << "    ";
	}
	cout << root->name << endl;
	if (root->left != NULL) {
		print_dir(root->left, level + 1);
	}
	if (root->right != NULL) {
		print_dir(root->right, level + 1);
	}
}

void display(Node& node) {
	if (node.is_dir == true) {
		cout << "Directory: " << node.name << endl;
		cout << "Path: " << node.path << endl << endl;

		print_dir(&node, 1);

	}
	else {
		cout << "File: " << node.name << endl;
	}
}

void copy(Node& data, Node& destination) {
	if (data.name == "" || destination.name == "") {
		cout << "Empty!" << endl;
		return;
	}
	if (destination.is_dir == false) {
		cout << "destination is not a direcotry! Failed!" << endl;
		return;
	}
	if (destination.left != NULL && destination.right != NULL) {
		cout << "Destination already full!" << endl;
		return;
	}
	destination.addChild(&data);

}
void move(Node& data, Node& destination, Tree& tree) {
	if (data.name == "" || destination.name == "") {
		cout << "Empty!" << endl;
		return;
	}
	if (destination.is_dir == false) {
		cout << "destination is not a direcotry! Failed!" << endl;
		return;
	}
	if (destination.left != NULL && destination.right != NULL) {
		cout << "Destination already full!" << endl;
		return;
	}
	destination.addChild(&data);
	deleteNode(data, tree);

}


void exportData(Node& root, ofstream& file) {
	if (root.name == "") {
		cout << "Empty tree" << endl;
		return;
	}
	file << root.name << endl;
	file << root.path << endl;
	file << root.is_dir << endl;
	if (root.left != NULL) {
		exportData(*root.left, file);
	}
	if (root.right != NULL) {
		exportData(*root.right, file);
	}
}

//export data(and paths) to txt file
void exportData(Tree& tree) {
	ofstream file;
	file.open("data.txt");
	exportData(*tree.getRoot(), file);
	file.close();


}

void importData(Node& root) {

ifstream file;
file.open("data.txt");
	if (root.name == "") {
		cout << "Empty tree" << endl;
		return;
	}
	string name;
	string path;
	bool is_dir;
	getline(file, name);
	getline(file, path);
	file >> is_dir;
	Node* node = new Node(name, path, is_dir);
	root.addChild(node);
	if (root.left != NULL) {
		importData(*root.left);
	}
	if (root.right != NULL) {
		importData(*root.right);
	}
}