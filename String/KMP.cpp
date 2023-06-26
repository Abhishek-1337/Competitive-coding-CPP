#include <bits/stdc++.h>
using namespace std;

void fillLPS(string str, int *lps)
{
    int n = str.length();
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
}

int main()
{
    string txt = "ababcababaad";
    string pat = "ababa";
    int m = txt.length();
    int n = pat.length();
    int lps[n] = {0};
    fillLPS(pat, lps);
    int i = 0, j = 0;

    while (i < m)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            cout << i - j;
            j = lps[j - 1];
        }
        else if (i < m && pat[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    return 0;
}