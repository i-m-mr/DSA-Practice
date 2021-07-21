#include <bits/stdc++.h>
using namespace std;
// #define int long long

int coinChange(int arr[], int n, int sum)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= sum; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[sum];
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

        int ans = coinChange(arr, n, sum);
        cout << "The Number of ways are : " << ans << endl;
    }
    return 0;
}