#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int m, int lps[])
{
    lps[0] = 1;
    int i = 1, len = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            pat[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index : " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}