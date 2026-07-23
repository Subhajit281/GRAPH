#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        vector<int> present(26, 0);

        for (auto &word : words)
            for (char c : word)
                present[c - 'a'] = 1;
                
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(present[i]) cnt++;
        }
                
        int V = 26;
        vector<vector<int>> adj(V);
        
        for(int i = 0 ; i < words.size() - 1 ; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size() , s2.size());
            
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2){
                return "";
            }
            
            for(int ptr = 0 ; ptr < len ; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        // topo sort (kahn's algo)
        
        vector<int> inDegree(V,0);
        for(int i = 0 ; i < V ; i++){
            for(auto& it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        
        for(int i = 0 ; i < V ; i++){
            if(present[i] && inDegree[i] == 0) q.push(i);
        }
        
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            ans += char(node +'a');
            q.pop();
            for(auto& it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(ans.size() != cnt) return "";
        return ans;
        
    }
};