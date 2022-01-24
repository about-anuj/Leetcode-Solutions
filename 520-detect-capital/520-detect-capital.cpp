class Solution {
public:
    bool detectCapitalUse(string w) {
       bool first=isupper(w[0]),allcap=true,allsmall=true;
        for(int i=1;i<w.size();i++)
        {
            if(isupper(w[i]))
                allsmall=false;
            if(islower(w[i]))
                allcap=false;
        }
       
        
        return (first and allcap) or allsmall;
    }
};