#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> dp;

long long int nPr(int n, int r)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            dp[i][j] = j * dp[i - 1][j - 1] + dp[i - 1][j];
            if (i == j)
            {
                break;
            }
        }
    }

    return dp[n][r];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        dp.resize(n + 1, vector<long long int>(r + 1, 0));

        long long int ans = nPr(n, r);
        cout << "Ans : " << ans << endl;
    }
    return 0;
}