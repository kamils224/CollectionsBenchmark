from IBenchmark import IBenchmark
from collections import UserList


class ListTest(IBenchmark):
    ls = UserList()
    num_of_operations = 100000

    def __init__(self, num_of_operations):
        self.num_of_operations = num_of_operations

    def add_test(self):
        for i in range(0, self.num_of_operations):
            to_add = len(self.ls)
            self.ls.append(to_add)

    def find_test(self):
        to_find = len(self.ls) - 1
        for i in range(0, self.num_of_operations):
            result = to_find in self.ls

    def remove_test(self):
        for i in range(0, self.num_of_operations):
            to_remove = self.ls[0]
            self.ls.remove(to_remove)

