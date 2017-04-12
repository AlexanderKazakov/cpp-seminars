#!/usr/bin/env python3

from decimal import *

print(round(0.735, 2))
print(Decimal('0.735').quantize(Decimal('0.01')))

print('dec:', sum([Decimal('0.1')]*10) == Decimal('1.0'))
print('bin:', sum([0.1]*10) == 1.0)

getcontext().prec = 36
print(Decimal(1) / Decimal(3))

