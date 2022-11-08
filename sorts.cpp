#include "bits/stdc++.h"
using namespace std;

//Selection Sort --> Time Complexity = O(n^2)
void SS(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Bubble Sort --> Time Complexity = O(n^2)
void BS(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int swap = 0;
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap++;
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }

        if (swap == 0)
        {
            break;
        }
    }
}

//Insertion Sort --> Time complexity == O(n^2)
void InsertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int j = i - 1;
        int key = arr[i];

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
    int a[] = {2, 65, 34, 12, 78, 90, 1000, 120};

    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Enter option:\n";
    cout << "1) Selection Sort\n";
    cout << "2) Bubble Sort\n";
    cout << "3) Insertion Sort\n";
    int op; cin >> op;

    if (op == 1)
        SS(a, 8);
    else if (op == 2)
        BS(a, 8);
    else if (op ==3)
        InsertionSort(a, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}