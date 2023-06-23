#include <bits/stdc++.h>
using namespace std;

#define d 256

int main()
{
    string txt = "abdabcbabc";
    string pat = "abc";
    int q = INT_MAX;
    int h = 1;
    int m = txt.size(), n = pat.size();

    // compute value of d^n-1
    for (int i = 1; i <= n - 1; i++)
    {
        h = (h * d) % q;
    }
    // compute hash value of pat and text
    int p = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    // cout << "m " << m << " n " << n << " h " << h << " p " << p << " t " << t << endl;
    for (int i = 0; i <= m - n; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                cout << i << " ";
            }
        }

        if (i < m - n)
        {
            t = (d * (t - txt[i] * h) + txt[i + n]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
    return 0;
}