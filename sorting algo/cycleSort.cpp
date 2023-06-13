#include <bits/stdc++.h>
using namespace std;

void cycleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int item = arr[i];
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < key)
            {
                pos++;
            }
        }
        swap(arr[pos], item);
        while (pos != i)
        {
            pos = i;
            item = arr[pos];
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < item)
                {
                    pos++;
                }
            }
            swap(arr[pos], item);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array to sort\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cycleSort(arr, n - 1);
    cout << "After sorting the array\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}