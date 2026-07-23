#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);

        //adj list with edge weight
        
        for(int i = 0 ; i < E ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //topo sort using bfs
        
        vector<int> sorted_res;
        queue<int> q;
        vector<int> inDegree(V,0);
        for(int i = 0 ; i < V ; i++){
            for(auto& it : adj[i]){
                inDegree[it.first]++;
            }
        }
        
        for(int i = 0 ; i < V ; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            sorted_res.push_back(node);
            q.pop();
            for(auto& it : adj[node]){
                inDegree[it.first]--;
                if(inDegree[it.first] == 0) q.push(it.first);
            }
        }
        
        //calculating distance
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        for (auto node : sorted_res) {
            if (dist[node] == INT_MAX) continue;
        
            for (auto &it : adj[node]) {
                int v = it.first;
                int wt = it.second;
        
                if (dist[v] > dist[node] + wt) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
       
        for(int i = 0 ; i < V ; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
