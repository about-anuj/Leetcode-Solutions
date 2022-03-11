class Solution {
public:
    int integerBreak(int n) {
     int prdct=1;
        
    if(n==2) return 1;
    if(n==3) return 2;
    
    while(n>4){
        n-=3;
        prdct*=3;
    }
        return prdct*n;
    }
};