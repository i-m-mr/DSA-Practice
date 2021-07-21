#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

class Solution
{
public:
    int lcs(int x, int y, int z, string s1, string s2, string s3)
    {
        if (x == 0 || y == 0 || z == 0)
        {
            return 0;
        }

        if (s1[x - 1] == s2[y - 1] && s2[y - 1] == s3[z - 1])
            return 1 + lcs(x - 1, y - 1, z - 1, s1, s2, s3);
        else
            return max(lcs(x - 1, y, z, s1, s2, s3),
                       max(lcs(x, y - 1, z, s1, s2, s3), lcs(x, y, z - 1, s1, s2, s3)));
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        Solution ob;
        cout << ob.lcs(x, y, z, s1, s2, s3) << endl;
    }
    return 0;
}