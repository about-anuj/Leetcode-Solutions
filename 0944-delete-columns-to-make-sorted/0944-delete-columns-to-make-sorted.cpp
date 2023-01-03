class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n=s.size(),res=0,m=s[0].size();
        for(int i=0;i<m;i++)
        { 
            string t="";
            for(int j=0;j<n;j++)
            {
                t+=s[j][i];
            }
            string a=t;
            sort(begin(t),end(t));
            if(a!=t)
                res++;
        }
        return res;
    }
};