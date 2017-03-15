#!/usr/bin/env python3

def foo(i):
	"""Write foo documentation here"""
	return 2 ** i

print("###################################################")

def bar(a, i = 5):
	a = i
	print("In bar: a ==", a)
	
a = 1
bar(a)
print("In main: a ==", a)
bar(i = 10, a = 4)

print("###################################################")

def f(a, L=[]):
    L.append(a)
    return L

print(f(1))
print(f(2))
print(f(3))

print("###################################################")

