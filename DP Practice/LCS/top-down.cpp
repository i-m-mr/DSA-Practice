#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int x, int y, string s1, string s2)
    {
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
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
        return dp[x][y];
    }
    int lcs(int x, int y, string s1, string s2)
    {
        dp.resize(x + 1, vector<int>(y + 1, 0));
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