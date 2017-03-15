#!/usr/bin/env python3

import sys

def divide(x, y):
    try:
        result = x / y
    except ZeroDivisionError:
        print("division by zero!")
    except:
        print("unexpected exception!")
    else:
        print("result is", result)
    finally:
        print("executing finally clause")

divide(1, 0)
divide(3, 2)
divide(1, 's')


with open("myfile.txt") as f:
    for line in f:
        print(line)
