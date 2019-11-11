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

            if (args.Length == 4)
            {
                if (args[0] == "-s")
                {
                    if (!int.TryParse(args[1], out samples))
                    {
                        Console.WriteLine("Parameter -s should be an unsigned integer!");
                        return;
                    }
                }
                if(args[2] == "-n")
                {
                    if (!int.TryParse(args[3], out numOfOperations))
                    {
                        Console.WriteLine("Parameter -n should be an unsigned integer!");
                        return;
                    }
                    string msg = string.Format("Running with parameters -s: {0}, -n: {1}",
                        samples, numOfOperations);
                    Console.WriteLine(msg);
                }
            }else
            {
                string msg = string.Format
                    ("Wrong parameters, " +
                    "running with default -s: {0}, -n: {1}",samples, numOfOperations);
                Console.WriteLine(msg);
            }

            List<BenchmarkResults> listResults = new List<BenchmarkResults>(samples);
            List<BenchmarkResults> hashsetResults = new List<BenchmarkResults>(samples);
            List<BenchmarkResults> dictionaryResults = new List<BenchmarkResults>(samples);

            ResultsManager listResultsManager = new ResultsManager()
            {
                CollectionName = "List",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                listResults.Add(benchmark.PerformAllTests());
                GC.Collect();
            }
            listResultsManager.SaveToCsv(listResults, "ListTest.csv");
            GC.Collect();

            ResultsManager dictResultsManager = new ResultsManager()
            {
                CollectionName = "Dictionary",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                dictionaryResults.Add(benchmark.PerformAllTests());
                GC.Collect();
            }
            dictResultsManager.SaveToCsv(listResults, "DictionaryTest.csv");
            GC.Collect();

            ResultsManager hashSetResultsManager = new ResultsManager()
            {
                CollectionName = "HashSet",
                NumberOfOperations = samples
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                hashsetResults.Add(benchmark.PerformAllTests());
                GC.Collect();
            }
            hashSetResultsManager.SaveToCsv(listResults, "HashSetTest.csv");
        }
    }
}
