#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll countFun(int arr[], int n, int k)
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 1 + dp[i - 1][j] + dp[i - 1][j / arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll ans = countFun(arr, n, k);
        cout << ans << endl;
    }

    return 0;
}