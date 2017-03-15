#!/usr/bin/env python3

print('All command line options:')
import sys
for arg in sys.argv:
	print(arg, end = ' ')
print('\n')

print('Simple way to parse options:')
import optparse
parser = optparse.OptionParser()
parser.add_option("-f", "--file",
                  help="set filename to the given value", metavar="A_FILE")
parser.add_option("-n", "--number", type='int', dest="num",
                  help="set num to the given value")
parser.add_option("-q", "--quiet",
                  action="store_false", dest="verbose", default=True,
                  help="set verbose to False")
parser.set_defaults(num = 0)
(options, args) = parser.parse_args()
print('Optional arguments:')
print('options.file ==', options.file,
	'options.verbose ==', options.verbose,
	'options.num ==', options.num)
print('Positional arguments:')
for arg in args:
	print(arg, end = ' ')
print()

