#include<bits/stdc++.h>
using namespace std;

void vertexCover(vector<int> adj[], int n) {
    vector<bool> visited(n , false);

    // checking each edge one by one
    for(int u=0; u<n; u++) {
        if(visited[u] == false) {
            for(auto v : adj[u]) {
                if(visited[v] == false) {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }

    // printing vertex cover
    for(int i=0; i<n; i++) {
        if(visited[i]) {
            cout << i << " ";
        }
    }
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> adj[n];

    for(int i=0; i<x; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vertexCover(adj, n);
    
    return 0;
}