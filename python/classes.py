#!/usr/bin/env python3

# В терминах C++ все члены классов -- public,
# все методы классов -- virtual


class B:
	def f(self):
		print('B.f()')
		self.g()
	def g(self):
		print('B.g()')

class D(B):
	def g(self):
		print('D.g()')

b = B()
b.f() 

d = D()
d.f() 

