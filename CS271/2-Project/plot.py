import matplotlib.pyplot as plt

import csv

inputSizes = []
mergeTimes = []
selectionTimes = []

with open('output.csv') as file:  
		lines = csv.reader(file, delimiter = ',') 
		for row in lines:
			inputSizes.append(row[0])
			mergeTimes.append(row[1])
			selectionTimes.append(row[2])
		plt.plot(inputSizes, mergeTimes)
		plt.plot(inputSizes, selectionTimes)
		plt.show()

