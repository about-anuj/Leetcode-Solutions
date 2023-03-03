class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        if(haystack.size()==0 or needle.size()==0) return 0;
        
        char c=needle[0];
        int n=needle.size();
        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
                if(haystack.substr(i,n)==needle)
                     return i;
            
        }
        return -1;
    }
};