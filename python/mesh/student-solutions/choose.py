f = open ('mesh-coarse.out', 'r')
#g = open ('temp_out.txt', 'w')
res = open ('out2.txt', 'w')
from math import sqrt
import sys

xc = float(sys.argv[1])
yc = float(sys.argv[2])
zc = float(sys.argv[3])
R =  float(sys.argv[4])


def ro_to_c(x, y, z):
	return sqrt ((x-xc)**2 + (y-yc)**2 + (z-zc)**2)
	

lines = f.readlines()
list1 = []
list2 = []
x0 = 0
y0 = 0
z0 = 0
list3 = dict()
j = 0
ind = 0
for line in lines:
	#print line
	if (len(line.split(' ')) == 3):
		#print line
		list1.append(line.split(' '))
	elif (len(line.split(' ')) == 5):
		#print line
		x0 = 0
		y0 = 0
		z0 = 0
		for i in line.split(' ')[0:-1]:
			 
			x0 = x0 + float(list1[int(i) - 1][0])
			y0 = y0 + float(list1[int(i) - 1][1])
			z0 = z0 + float(list1[int(i) - 1][2])
		
		x0 = 0.25*x0
		y0 = 0.25*y0
		z0 = 0.25*z0
		if (ro_to_c(x0, y0, z0) < R):
			list2.append(line.split(' '))
			#g.write (line) 
			for i in line.split(' ')[0:-1]:
				if ((int(i) - 1) not in list3):
					ind = ind + 1
					list3[int(i) - 1] = ind
				#print line, '   ', ind



#g.close()	
#g = open ('temp_out.txt', 'r')
j = 0
line2 = ''
for i in list1:
	j = j + 1
	if (j in list3): 
		res.write(str(i))
		#res.write('\n')
#print list3		
#glines = g.readlines()
for list_ in list2:
	line2 = ''
	for k in list_[0:-1]:
		line2 = line2 + ' ' + str(list3[int(k) - 1])
		
	#print list_
	line2 = line2 + ' ' + list_[-1]
	res.write(line2)


res.close()
f.close()


			
			
			
		

