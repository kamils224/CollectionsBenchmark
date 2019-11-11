﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace CS_Collections_benchmark
{
    class Benchmark
    {
        IBenchmark benchmark;
        BenchmarkResults results;
        Stopwatch sw = new Stopwatch();

        public Benchmark(IBenchmark benchmark)
        {
            this.benchmark = benchmark;
            results = new BenchmarkResults();
        }

        public BenchmarkResults PerformAllTests()
        {
            PerformAdd();
            PerformFind();
            PerformRemove();

            return results;
        }

        private void PerformAdd()
        {
            sw.Restart();
            benchmark.AddTest();
            sw.Stop();
            results.AddTime = sw.ElapsedMilliseconds;
        }
        private void PerformFind()
        {
            sw.Restart();
            benchmark.FindTest();
            sw.Stop();
            results.FindTime = sw.ElapsedMilliseconds;
        }

        private void PerformRemove()
        {
            sw.Restart();
            benchmark.RemoveTest();
            sw.Stop();
            results.RemoveTime = sw.ElapsedMilliseconds;
        }
    }
}
