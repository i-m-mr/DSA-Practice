#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

long long int nPr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0)
        return 1;

    if (dp[n][r] != -1)
        return dp[n][r];

    if (dp[n - 1][r - 1] == -1)
    {
        dp[n - 1][r - 1] = nPr(n - 1, r - 1);
    }
    if (dp[n - 1][r] == -1)
    {
        dp[n - 1][r] = nPr(n - 1, r);
    }

    return r * dp[n - 1][r - 1] + dp[n - 1][r];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        dp.resize(n + 1, vector<int>(r + 1, -1));

        long long int ans = nPr(n, r);
        cout << "Ans : " << ans << endl;
    }
    return 0;
}