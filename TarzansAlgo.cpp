#include<bits/stdc++.h>
using namespace std;


//Tarzan's Algo 

class Solution {
    int timer = 1;
private:
    void dfs(int node,int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,
             vector<int>& vis, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,adj,tin,low,vis,bridges);
                low[node] = min(low[node], low[it]);
                // node --- it
                if(low[it] > tin[node]) bridges.push_back({it,node});
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto it : connections) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> tin(n), low(n), vis(n);

        vector<vector<int>> bridges;
        dfs(0,-1,adj,tin,low,vis,bridges);
        return bridges;
    }
};