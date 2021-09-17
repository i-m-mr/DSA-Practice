#include<bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1, vector<int> (v+1, 0));

    for(int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    //print matrix
    for(int i=1; i<=v; i++) {
        cout << i << "-->   ";
        for(int j=1; j<=v; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}