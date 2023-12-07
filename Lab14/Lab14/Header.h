#pragma once
#include <iostream>

using namespace std;

class CityMap
{
private:
	int** map;
	int size;
public:
	CityMap()
	{
		size = 0;
		map = new int* [size];
		for (int i = 0; i < size; i++)
		{
			map[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				map[i][j] = 0;
			}
		}
	}
	CityMap(int size)
	{
		this->size = size;
		map = new int* [size];
		for (int i = 0; i < size; i++)
		{
			map[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				map[i][j] = 0;
			}
		}
	}

	void addCity()
	{
		int** newMap = new int* [size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			newMap[i] = new int[size + 1];
			for (int j = 0; j < size + 1; j++)
			{
				newMap[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				newMap[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < size; i++)
		{
			delete[] map[i];
		}
		delete[] map;
		map = newMap;
		size++;

		cout << "City added" << endl;
		cout << "City id: " << size - 1 << endl;
	}

	void addRoad(int from, int to, int distance)
	{
		map[from][to] = distance;
		map[to][from] = distance;
	}

	void printMap()
	{
		cout << "   ";
		for (int i = 0; i < size; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "  ";
			for (int j = 0; j < size; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}

	void findShortestPath(int start, int end)
	{
		int* distance = new int[size];
		int* previous = new int[size];
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++)
		{
			distance[i] = INT_MAX;
			previous[i] = -1;
			visited[i] = false;
		}
		distance[start] = 0;
		int current = start;
		while (current != end)
		{
			visited[current] = true;
			for (int i = 0; i < size; i++)
			{
				if (map[current][i] != 0 && !visited[i])
				{
					if (distance[current] + map[current][i] < distance[i])
					{
						distance[i] = distance[current] + map[current][i];
						previous[i] = current;
					}
				}
			}
			int min = INT_MAX;
			for (int i = 0; i < size; i++)
			{
				if (!visited[i] && distance[i] < min)
				{
					min = distance[i];
					current = i;
				}
			}
		}
		cout << "Shortest path from " << start << " to " << end << " is " << distance[end] << endl;
		cout << "Path: ";
		int currentCity = end;
		while (currentCity != start)
		{
			cout << currentCity << " ";
			currentCity = previous[currentCity];
		}
		cout << start << endl;
	}


};