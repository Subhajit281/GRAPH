#include<bits/stdc++.h>
using namespace std;

void generateRandomGraph(vector<vector<int>> graph,int n){
    double delta = 0.5;
    srand(time(0));
    
   // vector<vector<int>> graph(n, vector<int>(n,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int r = (double)rand()/RAND_MAX;
            
            if(r > delta){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(n,0));
    generateRandomGraph(graph , n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            cout<<graph[i][j]<<" ";
        }
    cout<<endl;
    }
    
}