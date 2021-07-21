#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    //declare adjacent list
    vector<int> adj[n + 1]; // If graph is weighted -->  vector<pair<int, int>> adj[n+1];

    // input edges in the list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // If graph is directed remove this...
    }

    return 0;
}