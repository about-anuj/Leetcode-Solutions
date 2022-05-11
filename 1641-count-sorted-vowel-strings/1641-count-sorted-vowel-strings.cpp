class Solution {
public:
    int ans=0,x;
   
    int countVowelStrings(int n) {
      int a=1,e=1,i=1,o=1,u=1;
        if(n==1) return 5;
        for(int j=2;j<=n;j++)
        {
            a+=e+i+o+u;
            e+=i+o+u;
            i+=o+u;
            o+=u;  
            
          //  cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u<<endl;
        }
        return a+e+i+o+u;
    }
};