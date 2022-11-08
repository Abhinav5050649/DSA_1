#include "bits/stdc++.h"
using namespace std;

int binSearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + floor((right - left)/2);

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }   

    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    cout << "Enter number you wish to look for in the array: ";
    int key = 0; cin >> key;

    int index = binSearch(arr, 0, 9, key);

    cout << "Element found at index " << index << endl;
}