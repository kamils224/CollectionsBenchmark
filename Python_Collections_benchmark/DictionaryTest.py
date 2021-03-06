from IBenchmark import IBenchmark
from collections import defaultdict


class DictionaryTest(IBenchmark):
    dictionary = defaultdict()
    num_of_operations = 10000

    def __init__(self, num_of_operations):
        self.num_of_operations = num_of_operations

    def add_test(self):
        for i in range(0, self.num_of_operations):
            to_add = len(self.dictionary)
            self.dictionary.setdefault(to_add, to_add)

    def find_test(self):
        to_find = len(self.dictionary) - 1
        for i in range(0, self.num_of_operations):
            result = to_find in self.dictionary.values()

    def remove_test(self):
        for i in range(0, self.num_of_operations):
            to_remove = len(self.dictionary) - 1
            self.dictionary.pop(to_remove)
