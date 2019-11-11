#pragma once
#include "IBenchmark.h"
#include "BenchmarkResults.h"

 class Benchmark
{
public:
	Benchmark(IBenchmark* benchmark);
	IBenchmark* benchmark;
	BenchmarkResults results = BenchmarkResults();
	BenchmarkResults* PerformAllTests();
private:
	void PerformAdd();
	void PerformFind();
	void PerformRemove();
};

