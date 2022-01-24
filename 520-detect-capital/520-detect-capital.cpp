class Solution {
public:
    bool detectCapitalUse(string w) {
        
        for(int i=1;i<w.size();i++)
        {
            if((isupper(w[1])!=isupper(w[i])) or (islower(w[0]) and isupper(w[i])))
                return false;
        }
        return true;
    }
};