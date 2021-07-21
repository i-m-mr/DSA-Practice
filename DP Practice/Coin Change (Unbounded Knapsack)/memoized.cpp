#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int coinChange(int coins[], int n, int amount)
{
    if (amount == 0)
        return 1;
    if (n == 0 || amount < 0)
        return 0;

    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }

    if (coins[n - 1] > amount)
    {
        dp[n][amount] = coinChange(coins, n - 1, amount);
        return dp[n][amount];
    }
    dp[n][amount] = coinChange(coins, n, amount - coins[n - 1]) + coinChange(coins, n - 1, amount);
    return dp[n][amount];
}

int solve(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
        return 0;

    dp.resize(n + 1, vector<int>(sum + 1, -1));

    dp[n][sum] = coinChange(arr, n, sum);
    return dp[n][sum];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        int ans = solve(arr, n, sum);
        cout << "The Number of ways are : " << ans << endl;
    }
    return 0;
}