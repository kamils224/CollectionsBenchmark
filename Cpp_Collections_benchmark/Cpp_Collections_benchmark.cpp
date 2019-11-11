#include <iostream>
#include "Benchmark.h"
#include "VectorTest.h"

int main()
{
	VectorTest vector = VectorTest(1000, 100);
	Benchmark benchmark(&vector);
	auto result = benchmark.PerformAllTests();

	std::cout << "Create and add: " << result->CreateAndAddTime << std::endl;
	std::cout << "Add: " << result->AddTime << std::endl;
	std::cout << "Find: " << result->FindTime << std::endl;
	std::cout << "Remove: " << result->RemoveTime << std::endl;
}