package com.company;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        int samples = 10;
        int numOfOperations = 100;
        boolean success = false;

        if (args.length == 4)
        {
            success = true;
            if (args[0].equals("-s"))
            {
                try {
                    samples = Integer.parseInt(args[1]);
                }catch (Exception e){
                    samples = 10;
                    success = false;
                }

            }
            if(args[2].equals("-n") )
            {
                try{
                    numOfOperations = Integer.parseInt(args[3]);
                }catch (Exception e){
                    numOfOperations = 100;
                    success = false;
                }

                String msg = String.format("Running with parameters -s: %1$s, -n: %2$s",
                        samples, numOfOperations);
                System.out.println(msg);
            }
        }

        if(!success)
        {
            String msg = String.format
                    ("Wrong parameters, " +
                            "running with default -s: %1$s, -n: %2$s",samples, numOfOperations);
            System.out.println(msg);
        }


        //ArrayList

        List<BenchmarkResults> listResults = new ArrayList<>(samples);
        List<BenchmarkResults> hashmapResults = new ArrayList<>(samples);
        List<BenchmarkResults> hashsetResults = new ArrayList<>(samples);

        ResultsManager listResultsManager = new ResultsManager();
        listResultsManager.CollectionName = "ArrayList";
        listResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            Benchmark benchmark = new Benchmark(new ArrayListTest(numOfOperations));
            listResults.add(benchmark.PerformAllTests());
        }
        try {
            listResultsManager.SaveToCsv(listResults, "Java_ListTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }


        //HashMap


        ResultsManager dictResultsManager = new ResultsManager();
        dictResultsManager.CollectionName = "HashMap";
        dictResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            Benchmark benchmark = new Benchmark(new HashMapTest(numOfOperations));
            hashmapResults.add(benchmark.PerformAllTests());
        }
        try {
            dictResultsManager.SaveToCsv(hashmapResults, "Java_HashMapTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }


        //HashSet

        ResultsManager hashSetResultsManager = new ResultsManager();
        hashSetResultsManager.CollectionName = "HashSet";
        hashSetResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            Benchmark benchmark = new Benchmark(new HashSetTest(numOfOperations));
            hashsetResults.add(benchmark.PerformAllTests());
        }
        try {
            hashSetResultsManager.SaveToCsv(hashsetResults, "Java_HashSetTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
