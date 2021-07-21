#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll countFun(int arr[], int n, int k)
{
    if (k < 1 || n == 0)
    {
        return 0;
    }

    if (arr[n - 1] > k)
    {
        return countFun(arr, n - 1, k);
    }
    return 1 + countFun(arr, n - 1, k) + countFun(arr, n - 1, k / arr[n - 1]);
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