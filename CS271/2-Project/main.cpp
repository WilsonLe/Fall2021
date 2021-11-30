#include <bits/stdc++.h>
#include <sys/time.h>
#include <fstream>

using namespace std;

void mergeSort(vector<int>& A){

}

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

void selectionSort(vector<int>& A){
	for (int i = 0; i < A.size() - 1; i++){
			int min_index = i;
			for (int j = i + 1; j < A.size(); j++){
				if (A[j] < A[min_index]){
					min_index = j;
				}
			}
			swap(A, min_index, i);
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

int ranInt(int start, int end){
	srand(time(NULL));
	return rand() % (end - start) + start;
}

vector<int> randomVector(int size, int minInt, int maxInt){
	vector<int> A;
	for (int i = 0; i < size; i++){
		A.push_back(ranInt(minInt, maxInt));
	}
	return A;
}

int main(){
	ofstream file;
	file.open("output.csv");
	for (int size = 100; size < 10000; size = size + 100){
		file << size << ",";
		// initialize array to be sorted, make sure both arrays are identical
		vector<int> mergeVector = randomVector(size, 0, 1000);
		vector<int> selectionVector = mergeVector;
		
		// Measure time for mergeSort
		timeval timeBeforeM, timeAfterM;
		long diffSecondsM, diffUSecondsM;
		gettimeofday(&timeBeforeM, NULL);

		mergeSort(mergeVector, 0, mergeVector.size() - 1);
		
		gettimeofday(&timeAfterM, NULL);
		diffSecondsM = timeAfterM.tv_sec - timeBeforeM.tv_sec;
		diffUSecondsM = timeAfterM.tv_usec - timeBeforeM.tv_usec;
		file << diffSecondsM + diffUSecondsM/1000000.0 << ",";

		// Measure time for selectionSort
		timeval timeBeforeS, timeAfterS;
		long diffSecondsS, diffUSecondsS;
		gettimeofday(&timeBeforeS, NULL);
		selectionSort(selectionVector);
		gettimeofday(&timeAfterS, NULL);
		diffSecondsS = timeAfterS.tv_sec - timeBeforeS.tv_sec;
		diffUSecondsS = timeAfterS.tv_usec - timeBeforeS.tv_usec;
		file << diffSecondsS + diffUSecondsS/1000000.0 << endl;
	}
	return 0;
}