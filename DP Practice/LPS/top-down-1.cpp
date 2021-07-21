#include <bits/stdc++.h>
using namespace std;

int longestPalinSubseq(string A);
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << longestPalinSubseq(s) << endl;
    }
}

int LCS(string s1, string s2, int n)
{
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}
int longestPalinSubseq(string S)
{
    int n = S.length();
    string str = S;
    reverse(S.begin(), S.end());
    return LCS(str, S, n);
}