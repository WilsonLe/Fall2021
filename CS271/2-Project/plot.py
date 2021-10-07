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
		
	plt.plot(inputSizes, mergeTimes, label='Merge Sort')
	plt.plot(inputSizes, selectionTimes, label='Selection Sort')
	plt.xlabel("Input Size")
	plt.ylabel("Time (s)")
	plt.text(0.1, 5000,'Merge')
	plt.text(2,4,'Selection')
	plt.title("Merge v/s Selection time")
	plt.legend(loc='best')
	plt.show()

