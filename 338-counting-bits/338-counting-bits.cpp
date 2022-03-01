class Solution {
public:
    int count(int n){
        int c=0;
        while(n)
        {
            if(n%2!=0)
                c++;
            
            n/=2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        int j=0;
        while(j<=n)
        {
            ans[j]=count(j);
            j++;
        }
        return ans;
    }
};