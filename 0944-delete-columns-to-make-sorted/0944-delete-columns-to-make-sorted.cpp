class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n=s.size(),res=0,m=s[0].size();
        for(int i=0;i<m;i++)
        { 
            string t="";
            for(int j=1;j<n;j++)
            {
                if(s[j][i]<s[j-1][i])
                {
                    res++;
                    break;
                }
            } 
        }
        return res;
    }
};