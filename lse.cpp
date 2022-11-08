#include "bits/stdc++.h"
using namespace std;

void linearSearch(int arr[], int n)
{
    int temp = -1, num = 0;
    cout << "Enter number you wish to search for: ";
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout << i << endl;
            temp = 0;
        }
    }

    if (temp == -1)
    {
        cout << "Not found\n";
    }
}

int main()
{
    int arr[] = {2, 5, 4, 7, 1, 89};
    linearSearch(arr, 6);
    return 0;
}