# Простой кодировщик строк

*Задание подразумевает использование stl.*

## Сначала сразу:

### Ввод
На стандартный ввод подаются строки. Не уникальные, в произвольном порядке. 
Число уникальных строк не превышает 10^6.

Затем пустая строка.

### Вывод
Целые числа, взаимно однозначно соответствующие строкам.

## Затем в интерактивном режиме:

### Ввод
Целое число.

### Вывод
Строка, соответствующая этому числу, либо сообщение об ошибке, если такой нет.

### Пример 
##### Ввод
```
abc
abc
xz
aaaa
abc
<пустая строка>
```
##### Вывод
```
0
0
1
2
0
```
##### Ввод
```
2
```
##### Вывод
```
aaaa
```
##### Ввод
```
0
```
##### Вывод
```
abc
```
##### Ввод
```
5
```
##### Вывод
```
<ошибка>
```
