class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        unordered_map<char,int>freq;
        int ind=0;
        
        for(auto i:words2)
        {
            unordered_map<char,int>t;
            for(auto &j:i)
            {
                t[j]++;
                //store max freq and if that char is present in the word1 then it should have greater or                     //equal freq
                freq[j]=max(freq[j],t[j]);
             }
            
        }
        
        for(auto &i:words1)
        {
            unordered_map<char,int>temp;
            bool ok=true;
            ind=0;
            
            for(auto j:i)
                temp[j]++;
            
            for(auto j:freq){
                if(temp[j.first]<j.second){
                    ok=false;
                    break;
                }
            }
            if(ok) ans.push_back(i);
        }
        return ans;
    }
};