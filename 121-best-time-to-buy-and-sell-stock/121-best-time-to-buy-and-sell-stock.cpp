class Solution {
public:
    int maxProfit(vector<int>& p) {
        int prevind,mn=INT_MAX,postind,mx=INT_MIN,ans=0;
        for(int i=0;i<p.size();i++)
        {
           if(p[i]<mn){
               mn=p[i];
               prevind=i;
           }
            else{
                mx=p[i];
                postind=i;
            }
            
            
            if(prevind<postind and mx>mn)
                ans=max(ans,mx-mn);
        }
        return ans;
    }
};