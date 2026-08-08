class Solution {
public:
   
    vector<int>solve(vector<int>&v)
    {
        vector<int>ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        ans.push_back(v[i]+v[i-1]);
        ans.push_back(v[v.size()-1]);
        return ans;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans={{1}};
        
        vector<int>cur={1};
     for(int i=1;i<n;i++)
     {
        cur=solve(cur);
        ans.push_back(cur);
     }
     return ans;
    }
};