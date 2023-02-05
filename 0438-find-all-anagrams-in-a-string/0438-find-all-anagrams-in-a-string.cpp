class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int>ans;
       vector<int>fix(26,0),temp(26,0);
        for(auto i:p) fix[i-'a']++;
        
        for(int i=0;i<s.length();i++)
        {
           if(i<p.length()-1) temp[s[i]-'a']++;
           else
            { //cout<<i-p.length()+1<<endl;
                temp[s[i]-'a']++;
                if(temp==fix)
                    ans.push_back(i-p.length()+1);
                
              //take care i made misstake here
                temp[s[i-p.length()+1]-'a']--;
            } 
        }
        return ans;
    }
};