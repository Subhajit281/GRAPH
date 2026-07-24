// Shortest Path Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		vector<vector<pair<int, int>> > adj(V);
		
		for (int i = 0 ; i < edges.size() ; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		vector<int> dist(V, INT_MAX);
		dist[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty()) {
			auto[distance, node] = pq.top();
			pq.pop();
			if (distance > dist[node]) continue ; // Skip outdated entry since a shorter distance to this node has already been processed.
			for (auto& it : adj[node]) {
				int new_dist = distance + it.second;
				if (dist[it.first] > new_dist) {
					dist[it.first] = new_dist;
					pq.push({new_dist, it.first});
				}
			}
		}
		return dist;
	}
};



// Unlike a set, a priority_queue cannot erase or update an outdated (distance, node) entry when a
// shorter path is found. Therefore, the same node may exist multiple times in the PQ with different
// distances. If the popped distance is greater than dist[node], it is a stale entry that can be
// safely skipped, since a shorter path has already been processed and relaxing its neighbors cannot
// produce a better result.