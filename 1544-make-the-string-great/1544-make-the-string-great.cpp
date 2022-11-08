class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        int mila=true;
        while(mila and s.size()>1)
        {
            string t="";
            bool should=false;
        for(int i=0;i<s.size();i++)
        {
            if(i<s.size()-1 and tolower(s[i])==tolower(s[i+1]) and s[i]!=s[i+1])
            {
                i++;
                should=true;
                continue;
            }
            t+=s[i];
        }
            mila=should;
            s=t;
        }
        return s;
    }
};