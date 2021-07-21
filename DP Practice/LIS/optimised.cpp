#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> v, int target)
    {
        int start = 0, end = v.size() - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (v[mid] >= target)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
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
                int j = binarySearch(v, arr[i]);
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