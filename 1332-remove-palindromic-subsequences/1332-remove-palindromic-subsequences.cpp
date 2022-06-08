class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)return 0;
        int a=0,b=s.size()-1;
        while(a<=b)
        {
            if(s[a]==s[b])
            {
                a++,b--;
            }
            else 
                return 2;
        }
        return 1;
    }
};