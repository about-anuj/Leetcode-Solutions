class Solution {
public:
    int brokenCalc(int st, int target) {
        int step=0;
        while(st<target)
        {
            if(target%2==0)
                target/=2;
            else
                target++;
            
            step++;
        }
        return step+st-target;
    }
};