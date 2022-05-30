class Solution {
public:
    int divide(int dividend, int divisor) {
     
        long long mod=pow(2,31);
        long long x=(long long)dividend;
        long long y=(long long)divisor;
        
        long long ans=x/y;
        if(ans>mod-1) return mod-1;
        if(ans<-1*mod) return -1*mod;
        return int(ans);
    }
};