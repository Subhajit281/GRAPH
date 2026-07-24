#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 1;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};

        while(!pq.empty()){
            auto[distance,cell] = pq.top();
            auto[r,c] = cell;
            pq.pop();
            if(dist[r][c] < distance) continue;
            for(int i = 0 ; i < 8 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                    int new_dist = distance + 1;
                    if(dist[nr][nc] > new_dist){
                        dist[nr][nc] = new_dist;
                        pq.push({new_dist,{nr,nc}});
                    }
                }    
            }
        }
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1] ;

    }
};