#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "ababacab";
    int n = str.length();
    int lps[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            bool flag = true;
            for (int k = 0; k < j; k++)
            {
                if (str[k] != str[i - j + k + 1])
                {
                    flag = false;
                }
            }
            if (flag)
                lps[i] = j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    return 0;
}