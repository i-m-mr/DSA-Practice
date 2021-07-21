#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<vector<int>> dp;

int coinChange(int arr[], int n, int sum)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int solve(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    dp.resize(n + 1, vector<int>(sum + 1, -1));
    int ans = coinChange(arr, n, sum);
    return ans;
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