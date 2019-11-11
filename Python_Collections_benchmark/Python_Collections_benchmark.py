from Benchmark import Benchmark
from ListTest import ListTest

if __name__ == '__main__':

    b = Benchmark(ListTest(1000))
    result = b.perform_all_tests()
    print(result.__dict__)
