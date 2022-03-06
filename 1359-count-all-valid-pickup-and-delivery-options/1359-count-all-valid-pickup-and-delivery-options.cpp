class Solution {
public:
    int m=1e9+7;
    long long mod(long long n){
        return (n%m+m)%m;
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    
    int countOrders(int n) {
        
    //total ways=n*(2n-1)*(2n-3)..... till n
       vector<long long>fact(501),ways(501);
        fact[0]=0;
        fact[1]=1;
        
        for(int i=2;i<=n;i++)
            fact[i]=mul(fact[i-1],(long long)i);
        
        ways[0]=1;
       for(int i=1;i<=n;i++)
           ways[i]=mul(ways[i-1],2LL*(i+1)-1);
        
        return mul(fact[n],ways[n-1]);
    }
};