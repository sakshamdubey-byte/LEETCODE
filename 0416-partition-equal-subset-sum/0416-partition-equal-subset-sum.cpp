class Solution {
public:
  bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp)
  {
    if(target==0)return true;
    if(idx==nums.size())return false;
    if(dp[idx][target]!=-1)return dp[idx][target];
   int take=false;
    if(target>=nums[idx])
    take=solve(idx+1,target-nums[idx],nums,dp);
    int nottake=solve(idx+1,target,nums,dp);
    

    return dp[idx][target]=(take||nottake);
  }

  bool canPartition(vector<int>& nums)
   {
     int sum=0;
    for(int i=0;i<nums.size();i++)
    sum+=nums[i];
  
    int target=sum/2;
    if (sum % 2 != 0) return false;
    vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));//-1 denotes unvisited
   return solve(0, target,nums,dp);
   }
};