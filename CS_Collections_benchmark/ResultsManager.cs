using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CS_Collections_benchmark
{
    class ResultsManager
    {
        private const string collectionInfo = "Collection name: {0},number of operations: {1},unit: {2}";
        private const string columns = "Add time,Find time,Remove time";
        private const string rowPattern = "{0},{1},{2}";
        private const string measureUnit = "ms";
        public string CollectionName = "None";
        public int NumberOfOperations = 0;
        public void SaveToCsv(List<BenchmarkResults> results, string path)
        {
            var csv = new StringBuilder();
            string firstRow = string.Format
                (collectionInfo, CollectionName, NumberOfOperations, measureUnit);
            string secondRow = columns;

            csv.AppendLine(firstRow);
            csv.AppendLine(secondRow);

            for (int i = 0; i < results.Count; i++)
            {
                var row = string.Format
                    (rowPattern,
                    results[i].AddTime, results[i].FindTime, results[i].RemoveTime);

                csv.AppendLine(row);
            }

            File.WriteAllText(path, csv.ToString());
        }

    }
}
