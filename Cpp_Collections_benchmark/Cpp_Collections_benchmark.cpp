#include <iostream>
#include <string>
#include <sstream>
#include "Benchmark.h"
#include "VectorTest.h"
#include <vector>
#include "ResultsManager.h"
#include "MapTest.h"
#include "SetTest.h"

int main(int argc, char **argv)
{
	int samples = 10;
	int numOfOperations = 100;
	bool success = false;
	if (argc == 4)
	{
		success = true;
		if (argv[0] == "-s")
		{
			std::stringstream arg1(argv[1]);
			if ((arg1 >> samples).fail() || !(arg1 >> std::ws).eof())
			{
				success = false;
			}
		}
		else
		{
			success = false;
		}

		if (argv[2] == "-n")
		{
			std::stringstream arg3(argv[3]);
			if ((arg3 >> numOfOperations).fail() || !(arg3 >> std::ws).eof())
			{
				success = false;
			}
		}
		else 
		{
			success = false;
		}
	}
	if(!success)
	{
		std::cout << "Wrong parameters, running with default -s: " << samples << ", -n: "
			<< numOfOperations << std::endl;
	}
	else
	{
		std::cout << "Running wit parameters -s: " << samples << ", -n: " 
			<< numOfOperations << std::endl;
	}

	std::vector<BenchmarkResults> vectorResults(samples);
	std::vector<BenchmarkResults> mapResults(samples);
	std::vector<BenchmarkResults> setResults(samples);

	//vector

	ResultsManager vectorResultsManager;
	vectorResultsManager.CollectionName = "Vector";
	vectorResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		VectorTest test(numOfOperations);
		Benchmark benchmark(&test);
		auto results = benchmark.PerformAllTests();
		vectorResults.push_back(*results);
	}
	vectorResultsManager.SaveToCsv(vectorResults, "Cpp_VectorTest.csv");

	//map

	ResultsManager mapResultsManager;
	mapResultsManager.CollectionName = "Map";
	mapResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		MapTest test(numOfOperations);
		Benchmark benchmark(&test);
		auto results = benchmark.PerformAllTests();
		mapResults.push_back(*results);
	}
	mapResultsManager.SaveToCsv(mapResults, "Cpp_MapTest.csv");

	//set

	ResultsManager setResultsManager;
	setResultsManager.CollectionName = "Set";
	setResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		SetTest test(numOfOperations);
		Benchmark benchmark(&test);
		auto results = benchmark.PerformAllTests();
		setResults.push_back(*results);
	}
	setResultsManager.SaveToCsv(setResults, "Cpp_SetTest.csv");

	return 0;
}