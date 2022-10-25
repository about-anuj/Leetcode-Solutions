class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return 1;
        for(int i=num/2;i<=num;i++)
        {
            string s=to_string(i);
            reverse(begin(s),end(s));
            int re=stoi(s);
            if(re+i==num) return 1;
        }
        return 0;
    }
};