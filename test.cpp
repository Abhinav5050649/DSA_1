#include "bits/stdc++.h"
using namespace std;

void InsertionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}	
}

int main()
{
	int arr[] = {2, 4, 1, 5, 7, 33, 12};

	InsertionSort(arr, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}