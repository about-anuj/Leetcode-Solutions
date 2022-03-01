class Solution {
public:
    string toLowerCase(string s) {
        //int j=0;
        for(auto &i:s)
            if(isupper(i))
               i+=32;
        
        return s;
    }
};