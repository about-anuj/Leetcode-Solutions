class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(p.size()<8)return 0;
        bool l=false,u=false,d=false,spch=false;
        string sp="!@#$%^&*()-+";
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>='a' and p[i]<='z')
                l=true;
            if(p[i]>='A' and p[i]<='Z')
                u=true;
            if(p[i]>='0' and p[i]<='9')
                d=true;
            for(auto j:sp)
                if(j==p[i])
                spch=true;
            
            if(i<p.size()-1 and p[i]==p[i+1])
                return false;
                
        }
        cout<<l<<u<<d<<spch;
        return l&&u&&d&&spch;
    }
};