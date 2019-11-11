#pragma once
#include "IBenchmark.h"
#include <unordered_set>
class SetTest : public IBenchmark
{
public:
	SetTest() : numOfOperations(100)
	{

	}
	SetTest(int numOfOperations) 
		: numOfOperations(numOfOperations)
	{

	}
	void addTest() override;
	void findTest() override;
	void removeTest() override;
private:
	std::unordered_set<int> set;
	int numOfOperations = 100;
};

