class Solution {
public:
    int mx=INT_MAX;
    void calc(vector<int>&v, int k,int i, int n,vector<int>&childs)
    {
        if(i==n){
            int temp=INT_MIN;
            for(int j=0;j<k;j++) 
                temp=max(childs[j],temp);
            
            mx=min(mx,temp);
            return;
        }
        
        for(int j=0;j<k;j++){
            childs[j]+=v[i];
            calc(v,k,i+1,n,childs);
            childs[j]-=v[i];
            
            if(!childs[j]) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(cookies.size(),0);
        calc(cookies,k,0,cookies.size(),child);
        return mx;
    }
};