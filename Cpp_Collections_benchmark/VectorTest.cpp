#include "VectorTest.h"
#include <algorithm>
#include <iostream>


void VectorTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		v.push_back(i);
	}
}

void VectorTest::findTest()
{
	int toFind = v[v.size() - 1];
	for (size_t i = 0; i < numOfOperations; i++)
	{
		auto it = std::find(v.begin(), v.end(), toFind);
	}
}

void VectorTest::removeTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toRemove = v[0];
		v.erase(std::remove(v.begin(), v.end(), toRemove),v.end());
	}
}

