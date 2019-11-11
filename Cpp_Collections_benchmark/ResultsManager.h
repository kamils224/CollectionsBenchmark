#pragma once
#include <vector>
#include <string>
#include "BenchmarkResults.h"
class ResultsManager
{
private:
	const std::string measureUnit = "ms";
	const std::string columns = "Add time, Find time, Remove time";

public:
	std::string CollectionName = "None";
	int NumberOfOperations = 0;

	void SaveToCsv(std::vector<BenchmarkResults>& results, std::string path);
};

