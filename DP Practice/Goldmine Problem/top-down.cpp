#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];
        for (int i = 0; i < n; i++)
        {
            dp[i][m - 1] = M[i][m - 1];
        }
        int ans = 0;
        for (int j = m - 2; j >= 0; j--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                int x = (i - 1 >= 0) ? dp[i - 1][j + 1] : 0;
                int y = (i + 1 < n) ? dp[i + 1][j + 1] : 0;
                int z = dp[i][j + 1];
                dp[i][j] = M[i][j] + max(x, max(y, z));
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}