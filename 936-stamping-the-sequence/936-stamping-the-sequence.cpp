class Solution {
public:
    int stmp(string stamp,string &tgt)
    {
        for(int i=0;i<tgt.size()-stamp.size()+1;i++)
        {
            bool find=true,wmatch=false;
            for(int j=0;j<stamp.size();j++)
            {
                if(tgt[i+j]=='*') continue;
                if(tgt[i+j]!=stamp[j]){
                    find=false;
                    break;
                }
                if(tgt[i+j]==stamp[j]) wmatch=true;
            }
            if(find and wmatch) 
            {
               for(int j=i;j<i+stamp.size();j++) tgt[j]='*';
                return i;
            }
        }
        return -1;
    }
    vector<int> movesToStamp(string stamp, string tgt) {
       stack<int>st;
        int turn=0;
       string transf="";
        unordered_set<char>s;
        for(auto i:tgt) s.insert(i);
        for(auto i:stamp)
            if(s.find(i)==s.end())
                return {};
        
        for(int i=0;i<tgt.size();i++) transf+="*";
        
        while(transf!=tgt)
        {
       ///   if(turn>=10*tgt.length()) return {};
          int ind=stmp(stamp,tgt);
            if(ind<0) return {};
          st.push(ind);
        //    turn++;
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};