#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    cout << "Enter the elements in the array\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp[n];
    int randomPivot = 4;
    int el = arr[randomPivot];
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < el)
        {
            temp[ind] = arr[i];
            ind++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= el)
        {
            temp[ind] = arr[i];
            ind++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
        cout << temp[i] << " ";
    }
    return 0;
}