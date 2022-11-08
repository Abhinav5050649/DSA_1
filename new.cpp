#include "bits/stdc++.h"
using namespace std;

void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1, key = arr[i];

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}//Issue resolved
}

int main()
{
	int arr[] = {2, 4, 1, 3, 89, 90, 67, 56, 45};
	int len = 9;

	InsertionSort(arr, len);

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}