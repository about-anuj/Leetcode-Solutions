class Solution {
public:
    string toLowerCase(string s) {
        int j=0;
        for(auto i:s)
            if(isupper(i))
               s[j++]=tolower(i);
            else
                j++;
        
        return s;
    }
};