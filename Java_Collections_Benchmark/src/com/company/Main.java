package com.company;

import java.io.IOException;
import java.util.*;

public class Main {

    static void Test()
    {
        int operations = 10000;
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i=0;i < operations; i++){
            mp.put(i,i);
        }

        long start = System.nanoTime();
        Integer toFind = mp.size()-1;
        for (int i=0;i < operations; i++){
            boolean result = mp.containsValue(toFind);
        }
        long end = System.nanoTime();

        System.out.printf("%f\n",(end - start)/1000000.0);

    }

    static void ArrayListBenchmark(int samples, int numOfOperations){
        //ArrayList
        List<BenchmarkResults> listResults = new ArrayList<>(samples);

        ResultsManager listResultsManager = new ResultsManager();
        listResultsManager.CollectionName = "ArrayList";
        listResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            System.out.println("Arraylist progress: "+ i + "/" + samples);
            Benchmark benchmark = new Benchmark(new ArrayListTest(numOfOperations));
            listResults.add(benchmark.PerformAllTests());
        }
        try {
            listResultsManager.SaveToCsv(listResults, "Java_ArrayListTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void HashMapBenchmark(int samples, int numOfOperations){
        //HashMap
        List<BenchmarkResults> hashmapResults = new ArrayList<>(samples);

        ResultsManager dictResultsManager = new ResultsManager();
        dictResultsManager.CollectionName = "HashMap";
        dictResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            System.out.println("Hashmap progress: "+ i + "/" + samples);
            Benchmark benchmark = new Benchmark(new HashMapTest(numOfOperations));
            hashmapResults.add(benchmark.PerformAllTests());
        }
        try {
            dictResultsManager.SaveToCsv(hashmapResults, "Java_HashMapTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void HashSetBenchmark(int samples, int numOfOperations){
        //HashSet
        List<BenchmarkResults> hashsetResults = new ArrayList<>(samples);

        ResultsManager hashSetResultsManager = new ResultsManager();
        hashSetResultsManager.CollectionName = "HashSet";
        hashSetResultsManager.NumberOfOperations = numOfOperations;

        for (int i = 0; i < samples; i++)
        {
            System.out.println("Hashset progress: "+ i + "/" + samples);
            Benchmark benchmark = new Benchmark(new HashSetTest(numOfOperations));
            hashsetResults.add(benchmark.PerformAllTests());
        }
        try {
            hashSetResultsManager.SaveToCsv(hashsetResults, "Java_HashSetTest.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {

        //Test();
        int samples = 10;
        int numOfOperations = 100;
        boolean success = false;

        Set<String> collectionNames = new HashSet<>(Arrays.asList("arraylist","hashmap", "hashset", "all"));
        String pickedCollection = "all";

        if (args.length == 5)
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

            if(collectionNames.contains(args[4])){
                pickedCollection = args[4];
            }else{
                success = false;
            }
        }

        if(!success)
        {
            String msg = String.format
                    ("Wrong parameters, " +
                            "running with default -s: %1$s, -n: %2$s",samples, numOfOperations);
            System.out.println(msg);
        }

        switch (pickedCollection){

            case "arraylist":
                ArrayListBenchmark(samples, numOfOperations);
                break;
            case "hashmap":
                HashMapBenchmark(samples, numOfOperations);
                break;
            case "hashset":
                HashSetBenchmark(samples, numOfOperations);
                break;
            case "all":
                ArrayListBenchmark(samples, numOfOperations);
                HashMapBenchmark(samples, numOfOperations);
                HashSetBenchmark(samples, numOfOperations);
                break;

            default:
                break;
        }

    }
}
