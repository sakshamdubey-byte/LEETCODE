class Solution {
public:
   vector<vector<int>> dp;

    int solve(int idx, vector<int>& nums, int target, int offset)
    {
     //we have two option + or -1
     if(idx == nums.size())
        return target == 0;
   if (abs(target) > offset) {
            return 0;
        }
     if(dp[idx][target + offset] != -1)
        return dp[idx][target + offset];

     int a = solve(idx + 1, nums, target - nums[idx], offset);
     int b = solve(idx + 1, nums, target + nums[idx], offset);

     return dp[idx][target + offset] = a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
       /* int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Edge cases:
        // 1. If (target + sum) is negative or odd, it's impossible to partition.
        // 2. If the absolute target is greater than the total sum, it's impossible.
        if ((target + sum) % 2 != 0 || (target + sum) < 0) return 0;

        int s1 = (target + sum) / 2;

        // dp[i][j] represents the number of subsets of the first i elements that sum to j
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));

        // Base case: There is 1 way to make a sum of 0 with 0 elements (the empty set)
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            // Start j from 0 to correctly process elements that are 0
            for (int j = 0; j <= s1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][s1];
        */

        // we are again going to write the recursive solution for this
        int offset = 0;
        for(int i = 0; i < nums.size(); i++)
            offset += abs(nums[i]);

        dp.resize(nums.size() + 1, vector<int>(2 * offset + 1, -1));

        return solve(0, nums, target, offset);
    }
};