#include "ResultsManager.h"
#include <fstream>
#include <iostream>

void ResultsManager::SaveToCsv(std::vector<BenchmarkResults>& results, std::string path)
{
	std::string csv = "";
	std::string firstRow = "Collection name: " + CollectionName +
		",number of operations: " + std::to_string(NumberOfOperations) + ",unit: " + measureUnit;
	csv += firstRow + "\n";
	csv += columns + "\n";

	std::ofstream out(path);
	out << csv;
	csv.clear();

	std::string res_size = std::to_string(results.size());
	int counter = 0;

	for (BenchmarkResults r : results)
	{
		std::string row = std::to_string(r.AddTime)
			+ "," + std::to_string(r.FindTime) + "," + std::to_string(r.RemoveTime);

		csv = row + "\n";
		out << csv;
		csv.clear();
		counter++;
		std::cout << "Saving " + CollectionName + " " + 
			std::to_string(counter) + "/" + res_size << std::endl;
	}

	out.close();
}