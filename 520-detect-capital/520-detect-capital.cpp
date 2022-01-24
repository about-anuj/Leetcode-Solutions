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
        //AAA
       if(first and allcap) return 1;
        // Aaa
        if(first and allsmall) return 1;
        //aaa
        if(allsmall) return 1;
        
        return 0;
    }
};