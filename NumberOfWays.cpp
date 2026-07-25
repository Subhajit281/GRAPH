#include<bits/stdc++.h>
using namespace std;

//Djikstra

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0 ; i < roads.size() ;i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int tm = roads[i][2];
            adj[u].push_back({v,tm});
            adj[v].push_back({u,tm});
        }

        vector<int> ways(n,0);
        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;
        ways[0] = 1;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;       
         pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            auto[tme,node] = pq.top();
            pq.pop();
            if(time[node] < tme) continue;

            for(auto& it : adj[node]){
                long long new_time = tme + it.second;
                if(time[it.first] > new_time){
                    time[it.first] = new_time;
                    ways[it.first] = ways[node];
                    pq.push({new_time,it.first});
                }
                else if(time[it.first] == new_time){
                    ways[it.first] = (ways[it.first] + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};

/*
Approach (Dijkstra + Counting Shortest Paths)

We use Dijkstra because all road travel times are non-negative.

Besides storing the shortest time to each node, we also maintain the
number of shortest paths reaching that node.

Data Structures:
1. time[i]  -> Minimum time required to reach node i.
2. ways[i]  -> Number of shortest paths to reach node i.

Initialization:
- Source node (0):
      time[0] = 0
      ways[0] = 1
  because there is exactly one way to be at the source initially.

Relaxation:

1. Found a STRICTLY SHORTER path:
      new_time < time[v]

   => Update the shortest time.
   => All previously known shortest paths become invalid.
   => Copy the number of ways from the current node.

      time[v] = new_time;
      ways[v] = ways[node];

2. Found ANOTHER SHORTEST path:
      new_time == time[v]

   => The shortest distance doesn't change.
   => We have discovered additional shortest paths.
   => Add the number of ways from the current node.

      ways[v] = (ways[v] + ways[node]) % MOD;

Priority Queue:
Stores {currentShortestTime, node}.
The stale-entry check skips outdated entries because priority_queue
cannot remove old values after a better distance is found.

Time Complexity:
O((V + E) log V)

Space Complexity:
O(V + E)
*/


/*
Mistakes / Things to Remember

1. Initially returned:
      return time[n-1];

   Wrong because the problem asks for the NUMBER OF SHORTEST PATHS,
   not the shortest distance.

   Correct:
      return ways[n-1];


2. Initially used:
      int time[]
      int new_time

   This can overflow because edge weights can be as large as 1e9.

   Correct:
      vector<long long> time(...)
      long long new_time


3. Initially wrote:

      ways[v] = ways[v] + ways[node] % MOD;

   Due to operator precedence, only ways[node] was taken modulo.

   Correct:

      ways[v] = (ways[v] + ways[node]) % MOD;


4. Important Dijkstra Observation:

   If a STRICTLY SHORTER path is found,
   replace the old path count.

        ways[v] = ways[node];

   If an EQUALLY SHORT path is found,
   accumulate the path counts.

        ways[v] = (ways[v] + ways[node]) % MOD;

   Never add path counts when a shorter path is found because
   the previous paths are no longer shortest.


5. Don't forget the stale-entry optimization:

      if (time[node] < tme) continue;

   Since priority_queue cannot delete outdated entries, ignore
   any entry whose time is worse than the current best time.
*/