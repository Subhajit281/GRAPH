#include<bits/stdc++.h>
using namespace std;

void dfs(int v , vector<int> adj[] , vector<int>& visited , vector<int>& result){

    // mark v as visited
    visited[v] = 1;

    result.push_back(v);

    for(int neighbor : adj[v]){        // explore its neighbors
        if(!visited[neighbor]){
            dfs(neighbor , adj , visited, result);     // if not visted go as deep as possible
        }
    }
}