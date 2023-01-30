class Solution {
public:
    int tribonacci(int n) {
      //  int t=n+5;
      
       long long int x,y,z,sum=0;
        x=0,y=1,z=1;
        
        if(n==1 or n==2) return 1;
        for(int i=3;i<n+1;i++)
        {
            sum=x+y+z;
            x=y,y=z,z=sum;
        }
        return sum;
    }
};