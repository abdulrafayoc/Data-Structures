#pragma once

#include <iostream>

using namespace std;


template <typename T>
class MyVector {
private:
	T* arr;
	int size;
public:
	MyVector() {
		arr = NULL;
		size = 0;
	}
	void addElement(T element) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = element;
		size++;
		arr = temp;
	}
	void removeElement(int index) {
		T* temp = new T[size - 1];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}
		for (int i = index; i < size - 1; i++) {
			temp[i] = arr[i + 1];
		}
		size--;
		arr = temp;
	}
	void changeElement(int index, T element) {
		arr[index] = element;
	}
	void getElements(int index) {
		cout << arr[index] << endl;
	}

};

