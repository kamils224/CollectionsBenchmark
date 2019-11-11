from IBenchmark import IBenchmark
from BenchmarkResults import BechmarkResults
from time import time_ns


class Benchmark:
    def __init__(self, ibenchmark: IBenchmark):
        self.ibenchmark = ibenchmark
        self.results = BechmarkResults()

    def perform_all_tests(self):
        self._perform_add()
        self._perform_find()
        self._perform_remove()

        return self.results

    def _perform_add(self):
        start = time_ns()
        self.ibenchmark.add_test()
        end = time_ns()
        self.results.add_time = (end - start)

    def _perform_find(self):
        start = time_ns()
        self.ibenchmark.find_test()
        end = time_ns()
        self.results.find_time = (end - start)

    def _perform_remove(self):
        start = time_ns()
        self.ibenchmark.remove_test()
        end = time_ns()
        self.results.remove_time = (end - start)

