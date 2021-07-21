#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> v;
        v.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > v[v.size() - 1])
            {
                v.push_back(arr[i]);
            }
            else
            {
                int j = 0;
                while (arr[i] > v[j])
                {
                    j++;
                }
                v[j] = arr[i];
            }
        }

        return v.size();
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