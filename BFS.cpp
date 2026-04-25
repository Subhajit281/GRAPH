#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(int v ,int vertices , vector<vector<int>>& adj){
    vector<int> visited(vertices+1, 0);
    vector<int> result;
    queue<int> q;              // main data structure for bfs 
    q.push(v);                 // push the first element
    visited[v] = 1;            // mark the first element as visited
    while(!q.empty()){         // till the queue is empty, traverse
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);       // store the vertex;

        for(int neighbor : adj[vertex]){     // explore its neighbor, mark them visited and push to queue
            if(!visited[vertex]){
                visited[neighbor] = 1;
                q.push(neighbor);
            }  
        }                                   // repeat the process till the queue is empty
    }
    return result;

}