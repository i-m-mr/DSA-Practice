#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll currAns = 0;
vector<vector<int>> dp;
void solve(int arr[], int n, int k) //  Incomplete Sol....
{
    if (k < 1 || n == 0)
    {
        return;
    }
    else if (k / arr[n - 1] >= 1)
        currAns++;

    solve(arr, n - 1, k / arr[n - 1]);
    solve(arr, n - 1, k);
}

ll countFun(int arr[], int n, int k)
{
    dp.resize(n + 1, vector<int>(k + 1, -1));
    solve(arr, n, k);
    return currAns;
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