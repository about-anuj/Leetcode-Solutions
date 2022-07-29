class Solution {
public:
    int totalMoney(int n) {
        int sum=1,ans=0;
        for(int i=1;i<=n;i++){
            ans+=sum;
            sum++;
            if(i%7==0)
                sum=(i+1)/7+1;
        }
        
        return ans;
    }
};