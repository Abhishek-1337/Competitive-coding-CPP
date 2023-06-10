#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int l, int r)
{
    int i = l - 1;
    int j = r + 1;
    int pivot = arr[l];
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, r);
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
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}