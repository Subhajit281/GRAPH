#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        // just relax all edges V-1 times 

        vector<int>  dist(V,1e8);
        dist[src] = 0;
        for(int i = 0 ; i < V-1 ; i++){
            for(auto& it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Negative edge cycle check (Vth iteration)
        for(auto& it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        
        
        return dist;
    }
};
