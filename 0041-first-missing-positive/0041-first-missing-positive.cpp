class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());
       int idx=-1;
       for(int i=0;i<nums.size();i++)
       {
        
        if(nums[i]>=1)
        {
            idx=i;break;
        }
       }
       if(idx==-1)return 1;
       int counter=1;
       int ans=-1;
       for(int i=idx;i<nums.size();i++)
       {
         if(i>idx && nums[i]==nums[i-1])continue;
          if(counter==nums[i])
          {
            ans=counter;
           
           
          }
          else
          {
            return counter;
          }
          counter++;
       }
       
       if(nums.size()-idx+1==counter)
       return counter;
       else
       return -1;
       
    }
};