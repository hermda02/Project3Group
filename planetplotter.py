import matplotlib.pyplot as plt
import numpy as np
import csv

x = []
y = []

with open('PlanetsVV_2_0.005.txt','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\t')
	for row in plots:
		x.append(row[3])
		y.append(row[4])
		

plt.plot(x,y)
plt.xlabel('AU')
plt.ylabel('AU')
plt.title('Plotted planets!')
plt.show()
