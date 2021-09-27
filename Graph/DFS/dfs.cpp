#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &ans, vector<int> &visited, int u)
    {
       visited[u] = 1;
       ans.push_back(u);
       for(auto x : adj[u]) {
           if(!visited[x]) {
               dfs(adj, ans, visited, x);
           }
       }

    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans;
        vector<int> visited(V, false);
        obj.dfs(adj, ans, visited, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}