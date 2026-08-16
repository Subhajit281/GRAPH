#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    class DisjointSet{
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

    public: 
        DisjointSet(int n){
            rank.resize(n,0);
            size.resize(n,1);
            for(int i = 0 ; i < n ; i++){
                parent.push_back(i);
            }
        };

        int findUParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            else if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u , int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
        
    };
    
    // int makeConnected(int n, vector<vector<int>>& connections) {

    //     DisjointSet ds(n);

    //     int components = n;
    //     int extra = 0;

    //     for(auto connection : connections){
    //         int u = connection[0];
    //         int v = connection[1];
    //         if(ds.findUParent(u) != ds.findUParent(v)){
    //             ds.unionByRank(u,v);
    //             components--;
    //         }else extra++;
    //     }

    //     if(extra >= components - 1){
    //         return components - 1;
    //     }
    //     return -1;

    // }
};