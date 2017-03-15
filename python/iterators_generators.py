#!/usr/bin/env python3

print('Iterator:')
class Reverse:
    """Iterator for looping over a sequence backwards."""
    def __init__(self, data):
        self.data = data
        self.index = len(data)
    def __iter__(self):
        return self
    def __next__(self):
        if self.index == 0:
            raise StopIteration
        self.index = self.index - 1
        return self.data[self.index]

l = [1, 2, 3]
rev_iter = Reverse(l)
for i in rev_iter:
    print(i)


print('Generator:')
def reverse(data):
    for index in range(len(data)-1, -1, -1):
        yield data[index]

for i in reverse(l):
    print(i)

# Функция range, как и выражение в скобках {} ниже -- это тоже "генераторы"
squares_table = {x: x**2 for x in range(0, 10)}

