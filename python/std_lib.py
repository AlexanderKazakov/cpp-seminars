#!/usr/bin/env python3

from datetime import date
flight_day = date(1961, 4, 12)
now = date.today()
age = now - flight_day
print(age.days, 'days gone')

print('##########################################################')

from timeit import Timer
print('t=a; a=b; b=t:', Timer('t=a; a=b; b=t', 'a=1; b=2').timeit())
print('a,b = b,a:', Timer('a,b = b,a', 'a=1; b=2').timeit())

print('##########################################################')

import math, random
print(math.cos(random.random()))

print('##########################################################')

import logging
logging.debug('Debugging information')
logging.info('Informational message')
logging.warning('Warning:config file %s not found', 'server.conf')
logging.error('Error occurred')
logging.critical('Critical error -- shutting down')

print('##########################################################')

