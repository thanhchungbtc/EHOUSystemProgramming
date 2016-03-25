// EHOUAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
extern "C" int ExcludeEvenNumber_(int* y, const int* x, int n); // return num elements of array y

void displayArray(const int* x, const int n) {
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}

void inputArray(int* &x, int& n) {

	cout << "Enter size of the array: ";
	cin >> n;
	if (x != NULL) {
		delete[] x;
	}
	x = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter item " << "[" << i << "]: ";
		cin >> x[i];
	}
}

int main() {

	int* x = NULL;
	int n;
	inputArray(x, n);	
	cout << "\nOriginal Array: \n";
	displayArray(x, n);
	int* y = new int[n]; // the result will be saved to this array
	int result = ExcludeEvenNumber_(y, x, n);

	cout << "\nAltered Array (After exclude even elements): \n";
	displayArray(y, result);

	
	system("pause");
	delete[] x;
	delete[] y;
	return 0;
}