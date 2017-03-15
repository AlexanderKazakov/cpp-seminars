#!/usr/bin/env python3

def foo(i, *arguments, **keywords):
	print("i =", i)
	
	print("arguments:")
	for arg in arguments:
		print(arg)
	
	print("keywords:")
	keys = sorted(keywords.keys())
	for kw in keys:
		print(kw, ":", keywords[kw])
	
	print('#' * 50)


foo(1)
foo(1, 's', 3)
foo(1, 's', k1 = 'c', k2 = 5)

