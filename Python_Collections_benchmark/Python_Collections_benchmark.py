import sys

from Benchmark import Benchmark
from ListTest import ListTest

def ignore_exception(IgnoreException=Exception,DefaultVal=None):
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
    num_of_operations = 100
    success = False

    sint = ignore_exception(ValueError)(int)

    if len(sys.argv) == 4:
        success = True
        if sys.argv[0] == '-s':
            samples = sint(sys.argv[1])
        if samples is None:
            samples = 10
            success = False



    b = Benchmark(ListTest(1000))
    result = b.perform_all_tests()
    print(result.__dict__)
