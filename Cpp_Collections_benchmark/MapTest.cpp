#include "MapTest.h"
#include <iostream>
#include <chrono>

void MapTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toAdd = map.size();
		map.insert({ toAdd ,toAdd });
	}
}

void MapTest::findTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toFind = map.size() - 1;
		auto results = findByValue(toFind);
	}
}

void MapTest::removeTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toRemove = map.size() - 1;
		map.erase(toRemove);
	}
}

bool MapTest::findByValue(int value)
{
	auto it = map.begin();
	// Iterate through the map
	while (it != map.end())
	{
		// Check if value of this entry matches with given value
		if (it->second == value)
		{
			// Yes found
			return true;
		}
		// Go to next entry in map
		it++;
	}
	return false;
}

	

