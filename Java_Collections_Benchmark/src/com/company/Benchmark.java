package com.company;


public class Benchmark {

    IBenchmark benchmark;
    BenchmarkResults results;

    public Benchmark(IBenchmark benchmark){
        this.benchmark = benchmark;
        results = new BenchmarkResults();
    }

    public BenchmarkResults PerformAllTests(){

        return results;
    }

    private void PerformAdd(){

        long start = System.currentTimeMillis();
        benchmark.AddTest();
        long end = System.currentTimeMillis();

        results.AddTime = end - start;
    }

    private void PerformFind(){

        long start = System.currentTimeMillis();
        benchmark.FindTest();
        long end = System.currentTimeMillis();

        results.FindTime = end - start;
    }

    private void PerformRemove(){

        long start = System.currentTimeMillis();
        benchmark.RemoveTest();
        long end = System.currentTimeMillis();

        results.RemoveTime = end - start;
    }

}
