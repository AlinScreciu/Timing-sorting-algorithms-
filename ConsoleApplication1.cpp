#include <iostream>
#include "sorts.h"
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	randomarr(arr, n);
	double test = time_sort_size(insertion_sort,arr,n);
	cout << fixed << test / 1000000000 <<" s"<< endl;
	delete[] arr;
	
	return 0;
}