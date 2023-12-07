#include "Header.h"

int main()
{
	CityMap map;
	int choice;
	do
	{
		cout << "1. new Insertion" << endl;
		cout << "2. New Road" << endl;
		cout << "3. Map" << endl;
		cout << "4. Shortest Path" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			map.addCity();
			break;
		case 2:
			int city1, city2, distance;
			cout << "Enter city id: ";
			cin >> city1;
			cout << "Enter city id: ";
			cin >> city2;
			cout << "Enter distance: ";
			cin >> distance;
			map.addRoad(city1, city2, distance);
			break;
		case 3:
			map.printMap();
			break;
		case 4:
			cout << "Enter city id: ";
			cin >> city1;
			cout << "Enter city id: ";
			cin >> city2;
			map.findShortestPath(city1, city2);
			break;
		case 5:
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	} while (choice != 5);

}