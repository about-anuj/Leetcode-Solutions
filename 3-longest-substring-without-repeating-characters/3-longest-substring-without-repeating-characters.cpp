class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int end=0,start=0,ans=0;
        unordered_set<char>freq;
        int len=s.size();
        ///end----start
        while(start<len)
        {
            if(freq.find(s[start])!=freq.end()){
               freq.erase(s[end]); 
               end++;
            }
            else{ 
                freq.insert(s[start]);
                start++;
                ans=max(ans,start-end);
            }
        }
        return ans;
    }
};