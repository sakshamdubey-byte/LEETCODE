#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& sus) 
    {
        sus[u] = true;
        for (int v : adj[u]) {
            if (!sus[v])
             {
                dfs(v, adj, sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations)
        {
            adj[edge[0]].push_back(edge[1]);
        }
       vector<bool>sus(n,false);
       dfs(k,adj,sus);
       bool not_remove=false;
       for(const auto&edge :invocations)
       {
        int u=edge[0];
        int v=edge[1];
        if(!sus[u] && sus[v]){
            not_remove=true;
            break;
        }
       }
      vector<int>ans;
      for(int i=0;i<n;i++)
      {
        if(not_remove|| !sus[i])
        {
            ans.push_back(i);
        }
      }
        return ans;
    }
};