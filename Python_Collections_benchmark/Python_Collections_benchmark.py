import sys

from Benchmark import Benchmark
from ListTest import ListTest
from ResultsManager import ResultsManager
from DictionaryTest import DictionaryTest
from SetTest import SetTest


def ignore_exception(IgnoreException=Exception, DefaultVal=None):
    """ Decorator for ignoring exception from a function
    e.g.   @ignore_exception(DivideByZero)
    e.g.2. ignore_exception(DivideByZero)(Divide)(2/0)
    """

    def dec(function):
        def _dec(*args, **kwargs):
            try:
                return function(*args, **kwargs)
            except IgnoreException:
                return DefaultVal

        return _dec

    return dec


if __name__ == '__main__':

    samples = 10
    num_of_operations = 10000
    success = False

    sint = ignore_exception(ValueError)(int)

    if len(sys.argv) == 4:
        success = True
        if sys.argv[0] == '-s':
            samples = sint(sys.argv[1])
        if samples is None:
            samples = 10
            success = False

        if sys.argv[2] == '-n':
            num_of_operations = sint(sys.argv[3])
        if num_of_operations is None:
            num_of_operations = 100
            success = False

    if not success:
        print('Wrong parameters, running with default -s: ' + str(samples) + ', -n: ' + str(num_of_operations))
    else:
        print('Running with parameters -s: ' + str(samples) + ', -n: ' + str(num_of_operations))

    list_results = list()
    dictionary_results = list()
    set_results = list()

    # list

    list_results_manager = ResultsManager()
    list_results_manager.collection_name = 'List'
    list_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        benchmark = Benchmark(ListTest(num_of_operations))
        list_results.append(benchmark.perform_all_tests())

    list_results_manager.save_to_csv(list_results, 'Python_ListTest.csv')

    # dictionary

    dict_results_manager = ResultsManager()
    dict_results_manager.collection_name = 'Dictionary'
    dict_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        benchmark = Benchmark(DictionaryTest(num_of_operations))
        dictionary_results.append(benchmark.perform_all_tests())

    dict_results_manager.save_to_csv(list_results, 'Python_DictionaryTest.csv')

    # set

    set_results_manager = ResultsManager()
    set_results_manager.collection_name = 'Set'
    set_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        benchmark = Benchmark(SetTest(num_of_operations))
        set_results.append(benchmark.perform_all_tests())

    set_results_manager.save_to_csv(list_results, 'Python_SetTest.csv')
