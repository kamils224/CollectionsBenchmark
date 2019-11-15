package com.company;


public class Benchmark {

    IBenchmark benchmark;
    BenchmarkResults results;

    public Benchmark(IBenchmark benchmark){
        this.benchmark = benchmark;
        results = new BenchmarkResults();
    }

    public BenchmarkResults PerformAllTests(){

        PerformAdd();
        PerformFind();
        PerformRemove();
        return results;
    }

    private void PerformAdd(){

        long start = System.nanoTime();
        benchmark.AddTest();
        long end = System.nanoTime();

        results.AddTime = (end - start)/1000000.0;
    }

    private void PerformFind(){

        long start = System.nanoTime();
        benchmark.FindTest();
        long end = System.nanoTime();

        results.FindTime = (end - start)/1000000.0;
    }

    private void PerformRemove(){

        long start = System.nanoTime();
        benchmark.RemoveTest();
        long end = System.nanoTime();

        results.RemoveTime = (end - start)/1000000.0;
    }

}
