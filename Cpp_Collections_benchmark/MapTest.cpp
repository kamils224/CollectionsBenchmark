#include "MapTest.h"
#include <iostream>
#include <chrono>
#include <algorithm>

void MapTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		map.insert({ i ,i });
	}
}

void MapTest::findTest()
{
	int toFind = map.size() - 1;
	bool result = false;
	for (size_t i = 0; i < numOfOperations; i++)
	{
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if (it->second == toFind)
			{
				result = true;
			}
		}
	}
}

void MapTest::removeTest()
{
	int toRemove = map.size() - 1;
	for (size_t i = 0; i < numOfOperations; i++)
	{
		map.erase(toRemove);
		toRemove--;
	}
}


	

