class Solution {
public:
    int trap(vector<int>& height) {
        // water is only trapped on (big-small-big)
        int l=0;int r=height.size()-1;int total=0;
        int leftmax=height[0];
        int level=0;
        int rightmax=height[height.size()-1];
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>leftmax)
                leftmax=height[l];
                else
                total+=(leftmax-height[l]);

                l++;
            }
            else
            {
                if(height[r]>rightmax)
                rightmax=height[r];
                else
                total+=(rightmax-height[r]);

                r--;
            }

          
        }
        return total ;
        
    }
};