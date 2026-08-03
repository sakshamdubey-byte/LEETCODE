class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& stoneValue, int idx)
    {
        if(idx >= stoneValue.size())
            return 0;
         if(dp[idx]!=-1)return dp[idx];
        int ans = INT_MIN;
        int sum = 0;

        for(int i = 0; i < 3 && idx + i < stoneValue.size(); i++)
        {
            sum += stoneValue[idx + i];
            dp[idx]=solve(stoneValue, idx + i + 1);
            ans = max(ans, sum - dp[idx]);
        }

        return dp[idx]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
       dp.resize(stoneValue.size(),-1);
        int diff = solve(stoneValue, 0);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
    }
};