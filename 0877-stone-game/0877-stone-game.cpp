class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&piles,int left,int right,int turn)
    {
        //at each stage we have two option 
        //alice turn
        if(left>right)return 0;
       if(dp[left][right][turn]!=-1)return dp[left][right][turn];
        if(turn==0)
        {
          //tryy to maximise itself 
          return dp[left][right][turn]=max(piles[left]+solve(piles,left+1,right,!turn),piles[right]+solve(piles,left,right-1,!turn ));
        }
        else 
        {
        // bob tries to minimise alice 
           return dp[left][right][turn]=min(piles[left]+solve(piles,left+1,right,!turn ),piles[right]+solve(piles,left,right-1,!turn ));
        }
        
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=0;
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        for(int i=0;i<piles.size();i++)
        sum+=piles[i];
        //turn 0 represnt of alic and turn 1 represent  bob
       int x= solve(piles,0,n-1,0);
       if(x>(sum+1)/2)return true;
       else return false ;
    }
};