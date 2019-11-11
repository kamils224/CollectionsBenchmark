#pragma once
#include "IBenchmark.h"
#include <unordered_map>

class MapTest : public IBenchmark
{
public:
	MapTest() : numOfOperations(100)
	{

	}
	MapTest(int numOfOperations) 
		: numOfOperations(numOfOperations)
	{

	}
	void addTest() override;
	void findTest() override;
	void removeTest() override;
private:
	std::unordered_map<int,int> map;
	int numOfOperations = 100;

	bool findByValue(int value);

};

