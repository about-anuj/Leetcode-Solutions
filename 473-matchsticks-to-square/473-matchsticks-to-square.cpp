class Solution {
public:
    bool vis[20];
    bool calc(vector<int>&st, int i, int n, int cursum, int req,int k)
    {
        if(k==1)
            return true;
        
        if(cursum==req)
            return calc(st,0,n,0,req,k-1);
        
        if(cursum>req) return 0;
        for(int j=i;j<n;j++){
            if(!vis[j]){
                vis[j]=true;
                if(calc(st,j+1,n,cursum+st[j],req,k))
                    return true;
                vis[j]=false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& stick) {
       int t=accumulate(begin(stick),end(stick),0),x=0;
        sort(begin(stick),end(stick));
        memset(vis,false,sizeof(vis));
        
        if(t%4!=0) return false;  //we want to use all sticks
        
       
        
        return calc(stick,0,stick.size(),0,t/4,4);
    }
};