class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt=0,set=-1;
        for(int i=0;i<=31;i++)
        {
            if((n & 1<<i)!=0)
            {
                cnt++;
                set=i;
            }
        }
        if(cnt>1 or set==-1) return 0;
        
        return (set)%2==0;
    }
};