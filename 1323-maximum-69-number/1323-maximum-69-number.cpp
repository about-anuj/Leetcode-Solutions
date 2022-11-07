class Solution {
public:
    int maximum69Number (int num) {
       int t=num,step=0,add=0;
        while(t)
        {
            if(t%10==6)
            {
                int a=pow(10,step);
                add=3*a;
            }
            t/=10;
            step++;
        }
        return num+add;
    }
};