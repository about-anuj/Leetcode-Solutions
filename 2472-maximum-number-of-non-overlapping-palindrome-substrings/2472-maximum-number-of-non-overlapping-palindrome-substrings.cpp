class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
          int l=i,r=i;
            while(l>=0 and r<n and s[l]==s[r] and s[l]!='$' and s[r]!='$')
            {
                if(r-l+1>=k)
                {
                    s[l]='$';
                    s[r]='$';
                ans++;
                    break;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
              while(l>=0 and r<n and s[l]==s[r] and s[l]!='$' and s[r]!='$')
            {
                if(r-l+1>=k)
                {
                    s[l]='$';
                    s[r]='$';
                ans++;
                    break;
                }
                r++;
                l--;
            }
            
        }
        return ans;
    }
};