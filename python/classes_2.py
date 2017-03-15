#!/usr/bin/env python3


class B:
	def __init__(self, param):
		print('B.__init__()')
		self.param = param

class D(B):
	def __init__(self, param):
		B.__init__(self, param)
		print('D.__init__()')

b = B(5)
d = D('c')

