class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
      
        // 1. Compute LCS Matrix
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(t1[i-1] == t2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int i = n, j = m;
        string ans = "";
        
        // 2. Reconstruct the SCS
        while(i > 0 && j > 0) {
            if(t1[i-1] == t2[j-1]) {
                ans.push_back(t1[i-1]);
                i--; j--;
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    ans.push_back(t1[i-1]);
                    i--;
                } else {
                    ans.push_back(t2[j-1]);
                    j--;
                }
            }
        }
        
        // FIX: Append remaining characters of t1 if t2 finished first
        while(i > 0) {
            ans.push_back(t1[i-1]);
            i--;
        }
        
        // FIX: Append remaining characters of t2 if t1 finished first
        while(j > 0) {
            ans.push_back(t2[j-1]);
            j--;
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};