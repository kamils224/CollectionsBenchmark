#include "SetTest.h"

void SetTest::addTest()
{
	for (size_t i = 0; i < numOfOperations; i++)
	{
		set.insert(i);
	}
}

void SetTest::findTest()
{
	int toFind = set.size() - 1;
	for (size_t i = 0; i < numOfOperations; i++)
	{
		auto result = set.find(toFind);
	}

}

void SetTest::removeTest()
{
	int toRemove = set.size() - 1;
	for (size_t i = 0; i < numOfOperations; i++)
	{
		set.erase(toRemove);
		toRemove--;
	}
}

