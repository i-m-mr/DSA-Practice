#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }
        int n = s1.length(), m = s2.length();
        if (n == 0)
            return true;
        if (n != m)
            return false;

        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }

        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            bool withoutSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                               isScramble(s1.substr(i), s2.substr(i));
            if (withoutSwap)
            {
                flag = true;
                break;
            }

            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                        isScramble(s1.substr(i), s2.substr(0, n - i));
            if (swap)
            {
                flag = true;
                break;
            }
        }

        return mp[key] = flag;
    }
};