#include <bits/stdc++.h>
using namespace std;

// naive solution
void naiveSelectionSort(int *arr, int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        int min_idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp[i] = arr[min_idx];
        arr[min_idx] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// efficient
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array"
         << "\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    naiveSelectionSort(arr, n);
    cout << "Sorting the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}