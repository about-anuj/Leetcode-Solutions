class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>ca,ta;
        for(auto i:s) ca[i]++;
        for(auto i:t) ta[i]++;
        
        for(auto i='a';i<='z';i++) 
            if(ca[i]!=ta[i])
                return false;
        
        return 1;
    }
};