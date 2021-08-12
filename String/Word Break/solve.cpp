#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        unordered_set<string> s;
        for (auto x : B)
        {
            s.insert(x);
        }
        int n = A.length();
        int dp[n + 1] = {0};
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            string str = "";
            for (int j = i; j < n; j++)
            {
                str += A[j];
                if (s.find(str) != s.end() && dp[j + 1])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}