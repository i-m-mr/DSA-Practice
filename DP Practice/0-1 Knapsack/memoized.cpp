#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int wt[], int val[], int n, int W)
    {
        dp.resize(n + 1, vector<int>(W + 1, -1));
        return knapsack(wt, val, n, W);
    }
    int knapsack(int wt[], int val[], int n, int W)
    {
        if (W <= 0 || n == 0)
        {
            return 0;
        }

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] <= W)
        {
            return dp[n][W] = max(val[n - 1] + knapsack(wt, val, n - 1, W - wt[n - 1]), knapsack(wt, val, n - 1, W));
        }
        else
        {
            return dp[n][W] = knapsack(wt, val, n - 1, W);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        int wt[n], val[n];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        Solution obj;
        cout << obj.solve(wt, val, n, W) << endl;
    }
    return 0;
}