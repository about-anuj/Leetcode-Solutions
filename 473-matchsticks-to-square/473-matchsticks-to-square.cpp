class Solution {
public:
    bool calc(vector<int>&a, int len, int sum, int j, int rem,vector<bool>&vis)
    {
        if(rem==0) return 1;
        
        if(sum==len)
            return calc(a,len,0,0,rem-1,vis);
        
        for(int i=j;i<a.size();i++)
        {
            if(sum+a[i]>len or vis[i]) continue;
            
            vis[i]=1;
            
            if(calc(a,len,sum+a[i],i+1,rem,vis))
                return 1;
            
            vis[i]=0;
            
        }
        return 0;
    }
    bool makesquare(vector<int>& mst) {
        int total=accumulate(begin(mst),end(mst),0);
        
        if(total%4!=0) return 0;
        
        int len=total/4;
        vector<bool>vis(mst.size(),false);
        return calc(mst,len,0,0,4,vis);
    }
};