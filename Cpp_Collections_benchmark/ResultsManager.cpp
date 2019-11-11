#include "ResultsManager.h"
#include <fstream>

void ResultsManager::SaveToCsv(std::vector<BenchmarkResults>& results, std::string path)
{
	std::string csv = "";
	std::string firstRow = "Collection name: " + CollectionName +
		",number of operations: " + std::to_string(NumberOfOperations) + ",unit: " + measureUnit;
	csv += firstRow + "\n";
	csv += columns + "\n";


	for (BenchmarkResults r : results)
	{
		std::string row = std::to_string(r.AddTime)
			+ "," + std::to_string(r.FindTime) + "," + std::to_string(r.RemoveTime);

		csv += row + "\n";
	}

	std::ofstream out(path);
	out << csv;
	out.close();
}