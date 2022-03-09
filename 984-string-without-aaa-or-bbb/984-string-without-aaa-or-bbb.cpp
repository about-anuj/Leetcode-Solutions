class Solution {
public:
    
    string strWithout3a3b(int a, int b) {
        string ans="";
        int ca=0,cb=0;
        while(a>0 or b>0)
        {
            if(a>=b and ca!=2 or cb==2)
            {
               ans.push_back('a');
               ca++;
               a--;
               cb=0;
            }
            else if(b>a and cb!=2 or ca==2)
            {
                ans.push_back('b');
                cb++;
                b--;
                ca=0;
            }
        }
        return ans;
    }
};