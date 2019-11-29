using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace CS_Collections_benchmark
{
    class Program
    {
        static void ListBenchmark(int samples, int numOfOperations)
        {
            List<BenchmarkResults> listResults = new List<BenchmarkResults>(samples);

            ResultsManager listResultsManager = new ResultsManager()
            {
                CollectionName = "List",
                NumberOfOperations = numOfOperations
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new ListTest(numOfOperations));
                listResults.Add(benchmark.PerformAllTests());
                Console.WriteLine(listResultsManager.CollectionName+" progress: "+ i + "/" + samples);
            }
            listResultsManager.SaveToCsv(listResults, "CSharp_ListTest.csv");
        }

        static void DictionaryBenchmark(int samples, int numOfOperations)
        {
            List<BenchmarkResults> dictionaryResults = new List<BenchmarkResults>(samples);
            ResultsManager dictResultsManager = new ResultsManager()
            {
                CollectionName = "Dictionary",
                NumberOfOperations = numOfOperations
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new DictionaryTest(numOfOperations));
                dictionaryResults.Add(benchmark.PerformAllTests());
                Console.WriteLine(dictResultsManager.CollectionName +"progress: "+i + "/" + samples);
            }
            dictResultsManager.SaveToCsv(dictionaryResults, "CSharp_DictionaryTest.csv");
        }

        static void HashSetBenchmark(int samples, int numOfOperations)
        {
            List<BenchmarkResults> hashsetResults = new List<BenchmarkResults>(samples);
            ResultsManager hashSetResultsManager = new ResultsManager()
            {
                CollectionName = "HashSet",
                NumberOfOperations = numOfOperations
            };

            for (int i = 0; i < samples; i++)
            {
                Benchmark benchmark = new Benchmark(new HashSetTest(numOfOperations));
                hashsetResults.Add(benchmark.PerformAllTests());
                Console.WriteLine(hashSetResultsManager.CollectionName + " progress: "+i + "/"+samples);
            }
            hashSetResultsManager.SaveToCsv(hashsetResults, "CSharp_HashSetTest.csv");
        }
        static void Main(string[] args)
        {
            int samples = 1;
            int numOfOperations = 10000;
            bool success = false;
            List<string> collectionType = new List<string>{ "list", "dict", "set", "all" };
            string pickedCollection = "dict";

            if (args.Length == 5)
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

                if (collectionType.Contains(args[4]))
                {
                    pickedCollection = args[4];
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
                string msg = string.Format("Running with parameters -s: {0}, -n: {1}, name: {2}",
                samples, numOfOperations, pickedCollection);
                Console.WriteLine(msg);
            }

            switch (pickedCollection)
            {
                case "list":
                    ListBenchmark(samples, numOfOperations);
                    break;
                case "dict":
                    DictionaryBenchmark(samples, numOfOperations);
                    break;
                case "set":
                    HashSetBenchmark(samples, numOfOperations);
                    break;
                case "all":
                    ListBenchmark(samples, numOfOperations);
                    DictionaryBenchmark(samples, numOfOperations);
                    HashSetBenchmark(samples, numOfOperations);
                    break;
                default:
                    break;
            }
        }
    }
}
