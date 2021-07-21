#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int arr[], int i, int temp)
    {
        if (i == n)
        {
            return 0;
        }

        int exclude = solve(n, arr, i + 1, temp);
        int include = 0;
        if (arr[i] > temp)
        {
            include = 1 + solve(n, arr, i + 1, arr[i]);
        }

        return max(include, exclude);
    }
    int longestSubsequence(int n, int a[])
    {
        return solve(n, a, 0, INT_MIN);
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}