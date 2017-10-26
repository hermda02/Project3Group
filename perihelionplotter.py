import matplotlib.pyplot as plt
import numpy as np
import csv

a = []
b = []
x = []
y = []
theta1 = []
theta = []
time = []
time1 = []
t1 = []
t2 = []
t = []
r = []
r1 = []

with open('PlanetsVV_2_0.001_merc.txt','r') as f:
	lines = f.readlines()
	time1 = [line.split()[0] for line in lines]
	a = [line.split()[3] for line in lines]
	b = [line.split()[4] for line in lines]

with open('PlanetsVV_2_0.001.txt','r') as f:
	lines = f.readlines()
	time = [line.split()[0] for line in lines]
	x = [line.split()[3] for line in lines]
	y = [line.split()[4] for line in lines]

x1 = a[::2]	
y1 = b[::2]
t2 = time1[::2]


for i in range(len(x1)):
	r1.append(np.sqrt(float(x1[i])*float(x1[i])+float(y1[i])*float(y1[i])))
	r.append(np.sqrt(float(x[i])*float(x[i])+float(y[i])*float(y[i])))


for i in range(len(x1)):
	if r1[i] < r1[i-1] and r1[i] < r1[i+1]:	
		theta1.append(np.arctan(float(y1[i])/float(x1[i])))
		t1.append(t2[i])
		theta.append(np.arctan(float(y[i])/float(x[i])))
		t.append(time[i])

plt.plot(t1,theta1,label="Relativistic Effect")
plt.plot(t,theta,label="Newtonian")
plt.xlabel('Time(Years)')
plt.ylabel('Perihelion Angle')
#plt.title('Plotted planets!')
plt.legend()
plt.show()
