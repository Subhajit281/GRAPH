#include<bits/stdc++.h>
using namespace std;


class Solution {

  private:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis,
             vector<int> &low, vector<int> &tin, vector<int> &mark) {
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,low,tin,mark);
                low[node] = min(low[node],low[it]);

                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1) mark[node] = 1;
    }

  public:
    vector<int> articulationPoints(int n, vector<vector<int>> &edges) {

        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0), low(n), tin(n), mark(n, 0), ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, low, tin, mark);
            }
        }
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1)
                ans.push_back(i);
        }
        if(ans.size() >0) return ans;
        return {-1};
    }
};
