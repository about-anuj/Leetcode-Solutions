class Solution {
public:
    int maxDistToClosest(vector<int>& seat) {
        int n=seat.size(),ans=0;
        vector<int>pre(n,0),suff(n,0);
        if(seat[0]==0)
            pre[0]=1;
        if(seat[n-1]==0)
            suff[n-1]=1;
        for(int i=1;i<n;i++)
            if(seat[i]==0)
                pre[i]=pre[i-1]+1;
            else
                pre[i]=0;
        
        for(int i=n-2;i>=0;i--)
            if(seat[i]==0)
                suff[i]=suff[i+1]+1;
            else
                suff[i]=0;
        
        ans=max(suff[0],pre[n-1]);
        for(int i=1;i<n-1;i++){
         int x=min(suff[i],pre[i]);
            ans=max(ans,x);
        }
        return (ans);
        }
};