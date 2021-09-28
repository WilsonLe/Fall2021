#include <bits/stdc++.h>

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

int main(){
	vector<int> A;
	A.push_back(5);
	A.push_back(3);
	A.push_back(1);
	A.push_back(2);
	
	mergeSort(A, 0, A.size()-1);
	// selectionSort(A);
	print(A);
	return 0;
}