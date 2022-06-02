class Solution {
public:
    unordered_set<string>st;
    vector<string>ans;
    string temp="";
    
    void calc(string &s, int pos)
    {
        //cout<<temp<<endl;
        if(pos==s.size())
        {
          //temp.erase(temp.end()-1);
            ans.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        
        for(int i=pos;i<s.size();i++)
        {
            string sub=s.substr(pos,i-pos+1);
            bool it=st.find(sub)!=st.end();
           // cout<<sub<<endl;
            if(it)
            {
                temp+=sub+" ";
                calc(s,i+1);
                temp.erase(temp.size()-sub.size()-1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       fillset(wordDict);
        calc(s,0);
        return ans;
    }
    
    private:
    void fillset(vector<string>& wordDict)
    {
        for(auto i:wordDict)
            st.insert(i);
    }
};