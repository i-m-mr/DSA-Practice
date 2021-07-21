#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0)
        {
            return 0;
        }

        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        if (s1[x - 1] == s2[y - 1])
        {
            if (dp[x - 1][y - 1] == -1)
                dp[x - 1][y - 1] = solve(x - 1, y - 1, s1, s2);
            return dp[x][y] = 1 + dp[x - 1][y - 1];
        }
        else
        {
            if (dp[x - 1][y] == -1)
                dp[x - 1][y] = solve(x - 1, y, s1, s2);
            if (dp[x][y - 1] == -1)
                dp[x][y - 1] = solve(x, y - 1, s1, s2);
            return dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        dp.resize(x + 1, vector<int>(y + 1, -1));
        return solve(x, y, s1, s2);
    }
};

int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}