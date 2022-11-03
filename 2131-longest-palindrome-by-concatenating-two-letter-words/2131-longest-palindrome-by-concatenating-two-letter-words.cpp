class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int ans=0;
        unordered_map<string,int>mp,mp1;
        for(auto i:words) 
            if(i[0]!=i[1]) 
                mp1[i]++;
             else
                 mp[i]++;
        
        for(auto i:mp1)
        {
            string t=i.first;
            reverse(begin(t),end(t));
            if(i.second!=0 and mp1[t]!=0)
             {
                    int x=min(mp1[t],mp1[i.first]);
                    mp1[t]-=x;
                    mp1[i.first]-=x;
                    ans+=4*x;
            }
        }
        int mx=0,odd=0;
        for(auto i:mp) {
            if(i.second%2==0)
               mx+=i.second;
            else{
                mx+=i.second-1;
                odd=true;
            }
        }
        if(odd) mx++;
        // if(mx==-1) mx=0;
        return ans+2*mx;
    }
};