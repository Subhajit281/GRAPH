// KAHN'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> inDegree(V,0);
        
        vector<vector<int>> adj(V);
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i = 0 ; i < V ; i++){
            for(auto& it : adj[i]){
                inDegree[it]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;
        
        for(int i = 0 ; i < inDegree.size() ; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto& it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            } 
        }
        return topo;
        
    }
};