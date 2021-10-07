import matplotlib.pyplot as plt
import numpy as np
import csv

inputSizes = []
mergeTimes = []
selectionTimes = []
heapTimes = []

with open('output.csv') as file:  
	lines = csv.reader(file, delimiter = ',') 
	for row in lines:
		inputSizes.append(float(row[0]))
		mergeTimes.append(float(row[1]))
		selectionTimes.append(float(row[2]))
		heapTimes.append(float(row[3]))
		
	plt.plot(inputSizes, mergeTimes, label='Merge Sort')
	plt.plot(inputSizes, selectionTimes, label='Selection Sort')
	plt.plot(inputSizes, heapTimes, label='Heap Sort')
	plt.xlabel("Input Size")
	plt.ylabel("Time (s)")
	plt.xticks(np.arange(0, max(inputSizes) + 1000, 1000))
	plt.title("Merge, Selection time, Heap sort")
	plt.legend(loc='best')
	plt.show()

