#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> v;
        vector<int> visited(V + 1, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    v.push_back(x);
                    for (auto u : adj[x])
                    {
                        if (visited[u] == false)
                        {
                            visited[u] = true;
                            q.push(u);
                        }
                    }
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