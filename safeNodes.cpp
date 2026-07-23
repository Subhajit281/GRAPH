
// Reversing the adj list to find the terminal nodes first then the safenodes

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int V = graph.size();

        vector<vector<int>> adjRev(V);

        vector<int> inDegree(V,0);

        for(int i = 0 ; i < V ; i++){
            for(auto& it : graph[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        for(int i = 0 ; i < V ; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;

        while(!q.empty()){
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            for(auto& it : adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        
        sort(safeNodes.begin() , safeNodes.end());
        return safeNodes;
    }
};