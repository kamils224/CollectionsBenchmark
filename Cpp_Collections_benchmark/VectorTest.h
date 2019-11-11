#pragma once
#include "IBenchmark.h"
#include <vector>
class VectorTest : public IBenchmark
{
public:
	VectorTest() : numOfOperations(100)
	{
	}
	VectorTest(int numOfOperations)
		: numOfOperations(numOfOperations)
	{
	}
	void addTest() override;
	void findTest() override;
	void removeTest() override;
private:
	std::vector<int> v;
	int numOfOperations = 100;
};

