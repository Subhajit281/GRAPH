#include<bits/stdc++.h>
using namespace std;

// Steps:

// 1. Topo sort and store in stack
// 2. transpose the graph (earlier a --> b ; now b <-- a)
// 3. apply DFS on transposed graph
// 4. print the DFS result line by line with each SCC in one line 

// The actual question was to count the number of Strongly Connected Components (SCC)

class Solution {
    
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void RevDfs(int node, vector<int>& vis, vector<vector<int>>& transpose){
        vis[node] = 1;
        for(auto it : transpose[node]){
            if(!vis[it]){
                RevDfs(it,vis,transpose);   
            }
        }
    }
    
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        //adj list
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        //topo-sort
        stack<int> st;
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        // transpose
        vector<vector<int>> transpose(V);
        for(auto it : edges){
            transpose[it[1]].push_back(it[0]);
        }
        
        // DFS on transpose list from stack pop
        for(int i = 0 ; i < V ; i++){
            vis[i] = 0;   // earlier all nodes were visited so for new dfs vis = 0
        }
        
        int count = 0 ;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                RevDfs(node,vis,transpose);
                count++;
            }
        }
        return count;
        
    }
};
