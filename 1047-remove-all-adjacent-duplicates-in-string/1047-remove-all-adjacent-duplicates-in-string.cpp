class Solution {
public:
    string removeDuplicates(string s) {
       int i=0;
        for(int j=0;j<s.size();j++)
        {
            s[i]=s[j];
            if(i>0 and s[i-1]==s[i]) i-=2;
            i++;
        }
        return s.substr(0,i);
    }
};