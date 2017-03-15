#!/usr/bin/env python3

for n in range(2, 10):
    for x in range(2, n):
        if n % x == 0:
            print(n, 'equals', x, '*', n//x)
            break
    else:
        # Выполняется по нормальному выходу из цикла
	# Если выход через break, не выполняется
        print(n, 'is a prime number')
