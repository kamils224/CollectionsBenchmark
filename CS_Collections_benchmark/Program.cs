using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace CS_Collections_benchmark
{
    class Program
    {
        static void Main(string[] args)
        {
            int samples = 10;
            int numOfOperations = 100;
            bool success = false;

            if (args.Length == 4)
            {
                success = true;
                if (args[0] == "-s")
                {
                    if (!int.TryParse(args[1], out samples))
                    {
                        success = false;
                    }
                }else
                {
                    success = false;
                }
                if(args[2] == "-n")
                {
                    if (!int.TryParse(args[3], out numOfOperations))
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
                string msg = string.Format
                    ("Wrong parameters, " +
                    "running with default -s: {0}, -n: {1}",samples, numOfOperations);
                Console.WriteLine(msg);
            }
            else
            {
                string msg = string.Format("Running with parameters -s: {0}, -n: {1}",
                samples, numOfOperations);
                Console.WriteLine(msg);
            }

            List<BenchmarkResults> listResults = new List<BenchmarkResults>(samples);
            List<BenchmarkResults> dictionaryResults = new List<BenchmarkResults>(samples);
            List<BenchmarkResults> hashsetResults = new List<BenchmarkResults>(samples);

            ResultsManager listResultsManager = new ResultsManager()
            {
                CollectionName = "List",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                listResults.Add(benchmark.PerformAllTests());
            }
            listResultsManager.SaveToCsv(listResults, "ListTest.csv");

            ResultsManager dictResultsManager = new ResultsManager()
            {
                CollectionName = "Dictionary",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                dictionaryResults.Add(benchmark.PerformAllTests());
            }
            dictResultsManager.SaveToCsv(listResults, "DictionaryTest.csv");

            ResultsManager hashSetResultsManager = new ResultsManager()
            {
                CollectionName = "HashSet",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                hashsetResults.Add(benchmark.PerformAllTests());
            }
            hashSetResultsManager.SaveToCsv(listResults, "HashSetTest.csv");
        }
    }
}
