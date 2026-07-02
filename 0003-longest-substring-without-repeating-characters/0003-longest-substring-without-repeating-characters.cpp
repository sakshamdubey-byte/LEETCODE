class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        map<char,int>hash;
        int n=s.size();
        int l=0;int r=0;
        int maxlength=INT_MIN;
        while(r<n)
        {
            
          if(hash[s[r]]==0)
          {
           
            hash[s[r]]=1;
            maxlength=max(maxlength,r-l+1);
          }
          else
          {
            while( s[l]!=s[r])
            {
               hash[s[l]]--;l++;
            }
            l++;
          }
          r++;
        }
     return maxlength;   
    }
};