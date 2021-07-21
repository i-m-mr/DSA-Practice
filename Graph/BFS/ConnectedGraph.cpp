#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> v;
        vector<int> visited(V + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = false;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            v.push_back(x);
            for (auto v : adj[x])
            {
                if (visited[v] == false)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return v;
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
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}