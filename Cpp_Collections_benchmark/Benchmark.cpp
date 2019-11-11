#include "Benchmark.h"
#include <chrono>
#include <iostream>


Benchmark::Benchmark(IBenchmark* benchmark)
{
	this->benchmark = benchmark;
}

BenchmarkResults* Benchmark::PerformAllTests()
{
	PerformAdd();
	PerformFind();
	PerformRemove();

	return &this->results;
}

void Benchmark::PerformAdd()
{
	auto start = std::chrono::high_resolution_clock::now();
	benchmark->addTest();
	auto end = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	results.AddTime = elapsed;
}

void Benchmark::PerformFind()
{
	auto start = std::chrono::high_resolution_clock::now();
	benchmark->findTest();
	auto end = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	results.FindTime = elapsed;
}

void Benchmark::PerformRemove()
{
	auto start = std::chrono::high_resolution_clock::now();
	benchmark->removeTest();
	auto end = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	results.RemoveTime = elapsed;
}

