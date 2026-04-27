#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {     // m x n matrix
        int m = grid.size();
        int n = grid[0].size();
        
        // {{r,c},t}
        queue<pair<pair<int,int> ,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));

        int cntFresh = 0;                  
        for(int  i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                if(grid[i][j] == 1) cntFresh++;            // to keep the count of fresh oranges
            }
        }
        int tm = 0;
        vector<int> deltaRow = {-1,0,1,0};           // neighbouring row track
        vector<int> deltaCol = {0,1,0,-1};          // neighbouring column track
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);                         // update timer
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + deltaRow[i];
                int ncol = c + deltaCol[i];
                if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});   // if neightbouring index in range & orange is not visited and fresh
                    visited[nrow][ncol] = 2;     // make it rotten 
                    cnt++;                       // count of rotting oranges
                }
            }
        }
        // for(int i = 0 ; i < m ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         if(visited[i][j] != 2 && grid[i][j] == 1) return -1;
        //     }
        // }
        // return tm; 
        if(cntFresh != cnt) return -1;          // if count of fresh oranges initially != count of rotting oranges
        return tm;                              // else return minimum time to rot all fresh roange

        
    }
};