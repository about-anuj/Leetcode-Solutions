class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
       // unordered_map<int,int>mp;
        sort(begin(p),end(p));
        int a=0,b=p.size()-1,ans=0;
        while(a<=b)
        {
             if(p[a]+p[b]<=limit)
               a++;
            
            b--;
            
            ans++;
        }
        return ans;
    }
};