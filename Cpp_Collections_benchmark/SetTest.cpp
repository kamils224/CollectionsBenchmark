#include "SetTest.h"

void SetTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toAdd = set.size();
		set.insert(toAdd);
	}
}

void SetTest::findTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toFind = set.size() - 1;
		auto result = set.find(toFind);
	}

}

void SetTest::removeTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		int toRemove = set.size() - 1;
		set.erase(toRemove);
	}
}

