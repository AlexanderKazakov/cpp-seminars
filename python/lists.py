#!/usr/bin/env python

l = [1, 2, 'string']
print(l)
print(l.pop())
print(l)
l.append(0)
print(l)
l.sort()
print(l)

l = [x**2 for x in range(10)]
print(l)
print("#" * 50)

l = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]
print(l)

l2 = list(zip(*l))
print(l2)

l3 = list(zip(*l2))
print(l3)
