class Solution {
public:
    
    string reformat(string s) {
        string c="",d="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
               c.push_back(s[i]);
            else 
               d.push_back(s[i]);
        }
        if(abs((int)c.size()-(int)d.size())>1) return "";
        bool alpha=c.size()>d.size();
        int i=0,j=0,k=0;
        while(i<s.length())
        {
            if(alpha)
            {
                s[i++]=c[j++];
            }
            else{
               s[i++]=d[k++];
            }
            alpha=!alpha;
        }
        return s;
    }
};