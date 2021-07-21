#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapsack(int wt[], int val[], int n, int W)
    {
        if (W == 0)
        {
            return 1;
        }
        if (n == 0 || W < 0)
        {
            return 0;
        }

        if (wt[n - 1] <= W)
        {
            return 1 + max(knapsack(wt, val, n - 1, W - wt[n - 1]), knapsack(wt, val, n - 1, W));
        }
        else
        {
            return knapsack(wt, val, n - 1, W);
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
        cout << obj.knapsack(wt, val, n, W) << endl;
    }
    return 0;
}