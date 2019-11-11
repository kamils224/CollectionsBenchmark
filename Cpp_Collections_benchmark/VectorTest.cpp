#include "VectorTest.h"
#include <algorithm>
#include <iostream>


void VectorTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toAdd = v.size();
		v.push_back(toAdd);
	}
}

void VectorTest::findTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toFind = v[v.size() - 1];
		auto it = std::find(v.begin(), v.end(), toFind);
	}
}

void VectorTest::removeTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toRemove = v[0];
		auto it = std::remove(v.begin(), v.end(), toRemove);
	}
}

