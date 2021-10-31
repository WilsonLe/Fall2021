#include <bits/stdc++.h>
#include <sys/time.h>
#include <fstream>
#include "heap.h"

using namespace std;

void swap(vector<int>& A, int x, int y){
	int temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}

void print(vector<int> A){
	for (int i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<int>& A){
	for (int j = 1; j < A.size(); j++){
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key){
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void merge(vector<int>& A, int left, int mid, int right){
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	// split A[left..right] into leftA, rightA
	vector<int> leftA;
	vector<int> rightA;
	for (int i = 0; i < leftSize; i++)
			leftA.push_back(A[left + i]);
	for (int j = 0; j < rightSize; j++)
			rightA.push_back(A[mid + 1 + j]);

	int indexLeft = 0; // Initial index of left array
	int indexRight = 0; // Initial index of right array
	int indexMerge = left; // Initial index of merged array

	// Merge leftA and rightA back into A[left..right]
	while (indexLeft < leftSize && indexRight < rightSize) {
			if (leftA[indexLeft] <= rightA[indexRight]) {
					A[indexMerge] = leftA[indexLeft];
					indexLeft++;
			}
			else {
					A[indexMerge] = rightA[indexRight];
					indexRight++;
			}
			indexMerge++;
	}
	// Append remaining elemnts of leftA to A
	while (indexLeft < leftSize) {
			A[indexMerge] = leftA[indexLeft];
			indexLeft++;
			indexMerge++;
	}
	// Append remaining elemnts of rightA to A
	while (indexRight < rightSize) {
			A[indexMerge] = rightA[indexRight];
			indexRight++;
			indexMerge++;
	}
}

void mergeSort(vector<int>& A, int begin, int end){
	if (begin >= end){
		return;
	}
	int mid = begin + (end - begin) / 2;
	mergeSort(A, begin, mid);
	mergeSort(A, mid + 1, end);
	merge(A, begin, mid, end);
}

void heapSort(vector<int>& A){
	int initA[A.size()];
	for (int i = 0; i < A.size(); i++){
		initA[i] = A[i];
	}
	MinHeap<int> heap = MinHeap<int>(initA, A.size());
	heap.heapSort(initA);
	for (int i = 0; i < A.size(); i++){
		A[i] = initA[i];
	}
}

int quickSortPartition(vector<int>& A, int p, int r){
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r - 1; j++){
		if (A[j] <= x){
			i++;
			swap(A, i, j);
		}
	}
	swap(A, i + 1, r);
	return i + 1;
}

void quickSort(vector<int>& A, int p, int r){
	if (p < r){
		int q = quickSortPartition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, p);
	}
}

int ranInt(int start, int end){
	return rand() % (end - start) + start;
}

vector<int> randomVector(int size, int minInt, int maxInt){
	srand(time(NULL));
	vector<int> A;
	for (int i = 0; i < size; i++){
		A.push_back(ranInt(minInt, maxInt));
	}
	return A;
}

void writeToCSV(){
	ofstream file;
	file.open("output.csv");
	for (int size = 100; size < 10000; size = size + 100){
		file << size << ",";
		// initialize array to be sorted, make sure both arrays are identical
		vector<int> mergeVector = randomVector(size, 0, 1000);
		vector<int> insertionVector = mergeVector;
		vector<int> heapVector = mergeVector;
		vector<int> quickVector= mergeVector;

		// Measure time for mergeSort
		timeval timeBeforeM, timeAfterM;
		long diffSecondsM, diffUSecondsM;
		gettimeofday(&timeBeforeM, NULL);
		mergeSort(mergeVector, 0, mergeVector.size() - 1);
		gettimeofday(&timeAfterM, NULL);
		diffSecondsM = timeAfterM.tv_sec - timeBeforeM.tv_sec;
		diffUSecondsM = timeAfterM.tv_usec - timeBeforeM.tv_usec;
		file << diffSecondsM + diffUSecondsM/1000000.0 << ",";

		// Measure time for insertionSort
		timeval timeBeforeS, timeAfterS;
		long diffSecondsS, diffUSecondsS;
		gettimeofday(&timeBeforeS, NULL);
		insertionSort(insertionVector);
		gettimeofday(&timeAfterS, NULL);
		diffSecondsS = timeAfterS.tv_sec - timeBeforeS.tv_sec;
		diffUSecondsS = timeAfterS.tv_usec - timeBeforeS.tv_usec;
		file << diffSecondsS + diffUSecondsS/1000000.0 << ",";

		// Measure time for heapSort
		timeval timeBeforeH, timeAfterH;
		long diffSecondsH, diffUSecondsH;
		gettimeofday(&timeBeforeH, NULL);
		heapSort(heapVector);
		gettimeofday(&timeAfterH, NULL);
		diffSecondsH = timeAfterH.tv_sec - timeBeforeH.tv_sec;
		diffUSecondsH = timeAfterH.tv_usec - timeBeforeH.tv_usec;
		file << diffSecondsH + diffUSecondsH/1000000.0 << ",";

		// Measure time for quickSort
		timeval timeBeforeQ, timeAfterQ;
		long diffSecondsQ, diffUSecondsQ;
		gettimeofday(&timeBeforeQ, NULL);
		quickSort(quickVector, 0, quickVector.size() - 1);
		gettimeofday(&timeAfterQ, NULL);
		diffSecondsQ = timeAfterQ.tv_sec - timeBeforeQ.tv_sec;
		diffUSecondsQ = timeAfterQ.tv_usec - timeBeforeQ.tv_usec;
		file << diffSecondsQ + diffUSecondsQ/1000000.0;

		file << endl;
	}
}

int main(){
	writeToCSV();
	return 0;
}