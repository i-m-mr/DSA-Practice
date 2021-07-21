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

int longestPalinSubseq(string S)
{
    int n = S.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int k = 0; k < n; k++)
    { // k -> gap
        for (int i = 0, j = k; j < n; i++, j++)
        {
            if (k == 0)
            {
                dp[i][j] = 1;
            }
            else if (k == 1)
            {
                dp[i][j] = (S[i] == S[j]) ? 2 : 1;
            }
            else
            {
                if (S[i] == S[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    return dp[0][n - 1];
}