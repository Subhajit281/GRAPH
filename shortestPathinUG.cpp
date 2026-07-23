#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        
        
        vector<vector<int>> adj(V);
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(V,INT_MAX);
        queue<pair<int ,int>> q;
        dist[src] = 0;
        q.push({src,0});
        while(!q.empty()){
            auto[node,distance] = q.front();
            q.pop();
            for(auto& it : adj[node]){
                int new_dist = distance + 1;
                if(dist[it] > new_dist){
                    dist[it] = new_dist;
                    q.push({it,dist[it]});
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
        
    }
};
