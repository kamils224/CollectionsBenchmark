#include <iostream>
#include <string>
#include <sstream>
#include "Benchmark.h"
#include "VectorTest.h"
#include <vector>
#include "ResultsManager.h"
#include "MapTest.h"
#include "SetTest.h"
#include <set>


void VectorBenchmark(int samples, int numOfOperations)
{
	//vector
	std::vector<BenchmarkResults> vectorResults(samples);
	ResultsManager vectorResultsManager;
	vectorResultsManager.CollectionName = "Vector";
	vectorResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		std::cout << "Vector progress: " << i << "/" << samples << std::endl;
		VectorTest* test = new VectorTest(numOfOperations);
		Benchmark benchmark(test);
		auto results = benchmark.PerformAllTests();
		vectorResults[i] = (*results);
		delete test;
	}
	vectorResultsManager.SaveToCsv(vectorResults, "Cpp_VectorTest.csv");
}

void uMapBenchmark(int samples, int numOfOperations)
{
	//map
	std::vector<BenchmarkResults> mapResults(samples);
	ResultsManager mapResultsManager;
	mapResultsManager.CollectionName = "Map";
	mapResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		std::cout << "Map progress: " << i << "/" << samples << std::endl;
		MapTest* test = new MapTest(numOfOperations);
		Benchmark benchmark(test);
		auto results = benchmark.PerformAllTests();
		mapResults[i] = (*results);
		delete test;
	}
	mapResultsManager.SaveToCsv(mapResults, "Cpp_MapTest.csv");
}

void uSetBenchmark(int samples, int numOfOperations)
{
	//set
	std::vector<BenchmarkResults> setResults(samples);
	ResultsManager setResultsManager;
	setResultsManager.CollectionName = "Set";
	setResultsManager.NumberOfOperations = numOfOperations;

	for (int i = 0; i < samples; i++)
	{
		std::cout << "Set progress: " << i << "/" << samples << std::endl;
		SetTest* test = new SetTest(numOfOperations);
		Benchmark benchmark(test);
		auto results = benchmark.PerformAllTests();
		setResults[i] = (*results);
		delete test;
	}
	setResultsManager.SaveToCsv(setResults, "Cpp_SetTest.csv");
}

int main(int argc, char **argv)
{
	int samples = 10;
	int numOfOperations = 100;
	bool success = false;

	std::set<std::string> collectionNames = { "vector", "map", "set", "all" };
	std::string pickedCollections = "all";

	if (argc == 6)
	{
		std::string a1(argv[1]);
		std::string a2(argv[2]);
		std::string a3(argv[3]);
		std::string a4(argv[4]);
		std::string a5(argv[5]);

		success = true;
		if (a1 == "-s")
		{
			std::stringstream arg1(a2);
			if ((arg1 >> samples).fail() || !(arg1 >> std::ws).eof())
			{
				success = false;
			}
		}
		else
		{
			success = false;
		}

		if (a3 == "-n")
		{
			std::stringstream arg3(a4);
			if ((arg3 >> numOfOperations).fail() || !(arg3 >> std::ws).eof())
			{
				success = false;
			}
		}
		else 
		{
			success = false;
		}

		if (collectionNames.find(a5) != collectionNames.end())
		{
			pickedCollections = a5;
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
		std::cout << "Running with parameters -s: " << samples << ", -n: " 
			<< numOfOperations << std::endl;
	}

	if (pickedCollections == "vector")
	{
		VectorBenchmark(samples, numOfOperations);
	}
	else if (pickedCollections == "map")
	{
		uMapBenchmark(samples, numOfOperations);
	}
	else if (pickedCollections == "set")
	{
		uSetBenchmark(samples, numOfOperations);
	}
	else if (pickedCollections == "all")
	{
		VectorBenchmark(samples, numOfOperations);
		uMapBenchmark(samples, numOfOperations);
		uSetBenchmark(samples, numOfOperations);
	}

	return 0;
}