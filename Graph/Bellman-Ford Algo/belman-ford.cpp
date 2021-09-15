#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        int m = edges.size();
	    
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0]=0;
	    
	    for(int i = 1; i <= n-1; i++){
	        
	        bool is_updating = true;
	        
	        for(int j = 0; j < m; j++){
	            
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int weight = edges[j][2];
	            
	            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
	                
	                dist[v] = dist[u] + weight;
	                is_updating = false;
	            }
	        }
	        
	        if(is_updating == true){
	            break;
	        }
	    }
	    
	     for(int j = 0; j < m; j++){
	            
	         int u = edges[j][0];
	         int v = edges[j][1];
	         int weight = edges[j][2];
	            
	         if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
	             return 1;
	         }
	      }
	    return 0;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			edges.push_back({u,v,w});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;   
}