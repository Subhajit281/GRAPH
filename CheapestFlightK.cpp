#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //adj list with price
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0 ; i < flights.size() ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int prc = flights[i][2];
            adj[u].push_back({v,prc});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto[stops,nodes] = q.front();
            auto[node,prc] = nodes;
            q.pop();

            for(auto&it : adj[node]){
                int stpCnt = stops + 1;
                int newPrc = prc + it.second;
                if(stpCnt <= k + 1){
                    if(prices[it.first] > newPrc){
                        prices[it.first] = newPrc;
                        q.push({stpCnt,{it.first,newPrc}});
                    }
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];

    }
};


/*
Approach (Modified BFS)

This problem cannot be solved using standard Dijkstra because the shortest cost
path is not always valid if it exceeds the allowed number of stops.

Observation:
- We are allowed at most 'k' intermediate stops, i.e. at most (k + 1) edges.
- Therefore, we process the graph level by level based on the number of stops
  instead of always expanding the minimum-cost path.

State stored in the queue:
    {stops_used, {current_node, current_cost}}

For every popped state:
1. Explore all outgoing flights.
2. Increase the stop count by one.
3. Compute the new travel cost.
4. If:
      - stops_used <= k + 1
      - and the new cost is cheaper than the best known cost for that node,
   then update the cost and push the new state into the queue.

Why a normal queue instead of a priority queue?
Because the primary constraint is the maximum number of stops.
We expand paths in increasing stop count (similar to BFS levels), ensuring
that we never consider paths using more than (k + 1) edges.

Time Complexity: O(E)
Space Complexity: O(V + E)
*/