#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool dfs(string wild, string pattern, int i, int j) {
        if(i == wild.size() && j == pattern.size()) {
            return true;
        }
        else if(i == wild.size()) {
            return false;
        }
        else if(j == pattern.size()) {
            return wild[i] == '*' && dfs(wild, pattern, i+1, j);
        }
        
        
        if(wild[i] == '*') {
            return dfs(wild, pattern, i+1, j) || dfs(wild, pattern, i, j+1);
        }
        else if(wild[i] == pattern[j] || wild[j] == '?') {
            return dfs(wild, pattern, i+1, j+1);
        }
    }
    bool match(string wild, string pattern)
    {
        return dfs(wild, pattern, 0, 0);
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