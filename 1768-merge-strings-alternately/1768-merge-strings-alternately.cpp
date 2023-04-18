class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=word1.size(),m=word2.size(),i=0;
       
        for(;i<min(n,m);i++)
        {
            res+=word1[i];
            res+=word2[i];
        }
        
        for(;i<n;i++) res+=word1[i];
        for(;i<m;i++) res+=word2[i];
        return res;
        }
};