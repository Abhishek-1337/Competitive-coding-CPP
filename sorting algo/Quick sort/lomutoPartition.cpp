#include <bits/stdc++.h>
using namespace std;

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
    int i = 0 - 1;
    int r = n - 1;
    int pivot = arr[r];
    for (int j = 0; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}