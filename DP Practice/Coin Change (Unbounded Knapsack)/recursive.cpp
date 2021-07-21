#include <bits/stdc++.h>
using namespace std;

long long int coinChange(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || n == 0)
    {
        return 0;
    }

    if (arr[n - 1] <= sum)
    {
        return coinChange(arr, n, sum - arr[n - 1]) + coinChange(arr, n - 1, sum);
    }
    else
    {
        return coinChange(arr, n - 1, sum);
    }
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

        long long int ans = coinChange(arr, n, sum);
        cout << "The Number of ways are : " << ans << endl;
    }
    return 0;
}