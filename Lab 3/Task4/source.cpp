#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	MyVector<int> BeautifulSoup;

	BeautifulSoup.addElement(0);
	BeautifulSoup.addElement(1);
	BeautifulSoup.addElement(2);
	BeautifulSoup.addElement(3);
	BeautifulSoup.addElement(4);
	BeautifulSoup.addElement(5);
	BeautifulSoup.addElement(6);
	BeautifulSoup.addElement(7);
	BeautifulSoup.addElement(8);
	BeautifulSoup.addElement(9);
	

	BeautifulSoup.removeElement(8);
	BeautifulSoup.changeElement(5, 69);

	for (int i = 0; i < 9; i++) {
		BeautifulSoup.getElements(i);
	}

}