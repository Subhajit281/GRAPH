#include<bits/stdc++.h>
using namespace std;

// Adjacency List

int main(){
    int m , n ;
    cin >> n >> m ;     // n -> no.of vertices ,  m -> no. of edges
    // for undirected graph
    // time conplexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v;
        // u -- v
        cin >> u >> v;          // node values
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for directed graph
    // time complexity: O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        // u —> v only
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}


// Adjacency Matrix ...

