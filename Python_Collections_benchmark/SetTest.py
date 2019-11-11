from IBenchmark import IBenchmark


class SetTest(IBenchmark):
    s = set()
    num_of_operations = 100

    def __init__(self, num_of_operations):
        self.num_of_operations = num_of_operations

    def add_test(self):
        for i in range(0, self.num_of_operations):
            to_add = len(self.s)
            self.s.add(to_add)

    def find_test(self):
        for i in range(0, self.num_of_operations):
            to_find = len(self.s) - 1
            result = any(to_find in x for x in self.s)

    def remove_test(self):
        for i in range(0, self.num_of_operations):
            to_remove = len(self.s) - 1
            self.s.remove(to_remove)

