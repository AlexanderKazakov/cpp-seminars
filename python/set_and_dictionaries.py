#!/usr/bin/env python3

a = set('abracadabra')
print(a)
b = set('alacazam')
print(b)
print(a - b)
print(a | b)
print(a & b)
print(a ^ b)


d = dict([('a', 3), ('b', 7), ('f', 9)])
for key, val in d.items():
	print(key + ' ==> ' + str(val))

knights = {'gallahad': 'the pure', 'robin': 'the brave'}
for index, key in enumerate(sorted(knights.keys())):
	print(index, key, knights[key])
