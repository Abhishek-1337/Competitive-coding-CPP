#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3, n = 3;
    int arr[m][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int temp[n][m];
    // naive solution
    //  for (int i = 0; i < m; i++)
    //  {
    //      for (int j = 0; j < n; j++)
    //      {
    //          temp[j][i] = arr[i][j];
    //      }
    //  }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // efficient solution
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}