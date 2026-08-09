#include<bits/stdc++.h>
using namespace std;


// count no. of components

class Solution {
public:
    int countIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
            
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                
                if(grid[i][j] == 'L' && !vis[i][j]) {

                    cnt++;             
                    queue<pair<int,int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {

                        auto [r, c] = q.front();
                        q.pop();

                        for(int k = 0; k < 8; k++) {

                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nr < n &&
                               nc >= 0 && nc < m &&
                               grid[nr][nc] == 'L' &&
                               !vis[nr][nc]) {

                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};