class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long x=left;
        // if((int)log2(left)!=log2(right)) return 0;
        for(long long i=left;i<=right;i++){
            x&=i;
           if(x==0) return 0;
        }

        return x;
    }
};