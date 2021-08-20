#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int n = wild.size(), m = pattern.size();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        for(int j=0; j<n; j++) {
            dp[0][j+1] = true;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(wild[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(((wild[i-1] == pattern[j-1]) || wild[i-1] == '?') && dp[i-1][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[n][m];
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}