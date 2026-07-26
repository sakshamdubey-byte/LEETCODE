class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s, string &t, int idx1, int idx2)
    {

        if ( idx2 == t.size()) return 1;
        else if(idx1==s.size() && idx2<=t.size()) return 0;
       if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if (s[idx1] == t[idx2])
        {
            //then we have two option consider that or not consider that
            int take = solve(s, t, idx1 + 1, idx2 + 1);
            int not_take = solve(s, t, idx1 + 1, idx2);
            return dp[idx1][idx2]=(take + not_take);
        }
        else
            return dp[idx1][idx2]=solve(s, t, idx1 + 1, idx2);

    }

    int numDistinct(string s, string t)
    {
        dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s, t, 0, 0);
    }
};