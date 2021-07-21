#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int arr[], int i, int j)
{
    if (i == j)
        return 0;

    int ans = INT_MAX;
    int count;

    for (int k = i; k < j; k++)
    {
        count = MatrixChainMultiplication(arr, i, k) + MatrixChainMultiplication(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
        ans = min(ans, count);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int ans = MatrixChainMultiplication(arr, 1, n - 1);
        cout << "Ans : " << ans << endl;
    }
    return 0;
}