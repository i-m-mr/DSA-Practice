#include <bits/stdc++.h>
using namespace std;
#define d 256

void solve(string txt, string pat, int q)
{
    int m = pat.length(), n = txt.length();
    int i, j;
    int p = 0; // pat hash value.
    int t = 0; // txt hash value.
    int h = 1;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
            {
                cout << "Pattern found at index : " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEKS";

    // q -->  any prime number
    int q = 101;

    solve(txt, pat, q);
    return 0;
}