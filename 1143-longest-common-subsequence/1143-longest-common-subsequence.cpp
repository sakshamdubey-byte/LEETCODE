class Solution {
public:
vector<vector<int>>dp;
    int lcs(string &a, string &b, int x, int y) {
        if (x < 0 || y < 0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if (a[x] == b[y]) {
            return dp[x][y]=1 + (lcs(a, b, x - 1, y - 1));
        }

        return dp[x][y]=max(lcs(a, b, x - 1, y), lcs(a, b, x, y - 1));
    }
    int longestCommonSubsequence(string t1, string t2) {
      dp.resize(t1.size()+1,vector<int>(t2.size()+1,-1));
      
        return lcs(t1, t2, t1.size() - 1, t2.size() - 1);
    }
};