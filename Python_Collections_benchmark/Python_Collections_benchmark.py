import sys

from Benchmark import Benchmark
from ListTest import ListTest
from ResultsManager import ResultsManager
from DictionaryTest import DictionaryTest
from SetTest import SetTest


def list_benchmark():
    # list
    list_results = list()

    list_results_manager = ResultsManager()
    list_results_manager.collection_name = 'List'
    list_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        print('Progress: ' + str(i) + '/' + str(samples))
        benchmark = Benchmark(ListTest(num_of_operations))
        list_results.append(benchmark.perform_all_tests())

    list_results_manager.save_to_csv(list_results, 'Python_ListTest.csv')


def dict_benchmark():
    # dictionary
    dictionary_results = list()

    dict_results_manager = ResultsManager()
    dict_results_manager.collection_name = 'Dictionary'
    dict_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        print('Progress: ' + str(i) + '/' + str(samples))
        benchmark = Benchmark(DictionaryTest(num_of_operations))
        dictionary_results.append(benchmark.perform_all_tests())

    dict_results_manager.save_to_csv(dictionary_results, 'Python_DictionaryTest.csv')


def set_benchmark():
    # set
    set_results = list()

    set_results_manager = ResultsManager()
    set_results_manager.collection_name = 'Set'
    set_results_manager.number_of_operations = num_of_operations

    for i in range(0, samples):
        print('Progress: ' + str(i) + '/' + str(samples))
        benchmark = Benchmark(SetTest(num_of_operations))
        set_results.append(benchmark.perform_all_tests())

    set_results_manager.save_to_csv(set_results, 'Python_SetTest.csv')


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

    samples = 1000
    num_of_operations = 100000
    success = False

    sint = ignore_exception(ValueError)(int)

    coll_names = ['list', 'dict', 'set', 'all']
    picked_coll = 'all'

    if len(sys.argv) == 6:
        success = True
        if sys.argv[1] == '-s':
            samples = sint(sys.argv[2])
        if samples is None:
            samples = 10
            success = False

        if sys.argv[3] == '-n':
            num_of_operations = sint(sys.argv[4])
        if num_of_operations is None:
            num_of_operations = 100
            success = False

        if sys.argv[5] in coll_names:
            picked_coll = sys.argv[5]
        else:
            success = False

    if not success:
        print('Wrong parameters, running with default -s: ' + str(samples) + ', -n: ' + str(num_of_operations))
    else:
        print('Running with parameters -s: ' + str(samples) + ', -n: ' + str(num_of_operations))

    if picked_coll == 'list':
        list_benchmark()
    elif picked_coll == 'dict':
        dict_benchmark()
    elif picked_coll == 'set':
        set_benchmark()
    elif picked_coll == 'all':
        list_benchmark()
        dict_benchmark()
        set_benchmark()
