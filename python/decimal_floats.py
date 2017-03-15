#!/usr/bin/env python3

from decimal import *
print('dec:', round(Decimal('0.70') * Decimal('1.05'), 2))
print('bin:', round(.70 * 1.05, 2))

print('dec:', sum([Decimal('0.1')]*10) == Decimal('1.0'))
print('bin:', sum([0.1]*10) == 1.0)

getcontext().prec = 36
print(Decimal(1) / Decimal(3))

