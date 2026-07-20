#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool bfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node] = 1;
        
        while(!q.empty()){
            auto[curr,parent] = q.front();
            q.pop();
            for(auto it : adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,curr});
                }
                else if(it != parent) return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Using Bfs
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        
        //adjacency list for undirected graph
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i] && bfs(i,vis,adj)) return true;
        }
        return false;
        
        
    }
};