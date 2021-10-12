#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public: 
    // bfs
    vector<int> kahnsAlgo(int V, vector<int> adj[]) 
	{
	    vector<int> in(V, 0), v;
	    for(int i=0; i<V; i++) {
	        for(auto x : adj[i]) in[x]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(in[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        
	        v.push_back(node);
	        
	        for(auto x : adj[node]) {
	            in[x]--;
	            if(in[x] == 0) q.push(x);
	        }
	    }
	    
	    return v;
	}


    // dfs implementation
	void dfs(vector<int> adj[], int src ,vector<int> &v, vector<int> &visited) {
	    visited[src] = true;
	    
	    for(auto x : adj[src]) {
	        if(visited[x] == false) {
	            dfs(adj, x, v, visited);
	        }
	    }
	    
	    v.push_back(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> v;
	    vector<int> visited(V, false);
	    for(int i=0; i<V; i++) {
	        if(!visited[i]) {
	            dfs(adj, i, v, visited);
	        }
	    }
	    reverse(v.begin(), v.end());
	   for(auto x : v) {
	       cout << x << endl;
	   }
	    return v;
	}
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
    }
    
    return 0;
}