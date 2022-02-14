class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //first save all the words in set for O(1)
        if(beginWord==endWord) return 0;
        unordered_set<string>st;
        for(auto i:wordList)
            st.insert(i);
        
        if(st.find(endWord)==st.end()) return 0;

        //to store similar words 
        queue<string>q;
        int ans=0;
        q.push(beginWord);
        //BFS
        while(!q.empty())
        {
            ans++;
            int sz=q.size();
            while(sz--)
            {
                string s=q.front();
                q.pop();
                cout<<s<<" ";
                for(int i=0;i<s.size();i++)
                {
                    //store the char
                 char c=s[i];
                 //set all the alphabets one by one
                 for(int j=0;j<26;j++)
                 {
                    s[i]='a'+j;
                    //if found in set then push the
                    //element in queue and delete from set
                    if(st.find(s)!=st.end())
                    {
                       q.push(s);
                       st.erase(s);
                    }
                    if(s==endWord)
                        return ans+1;
                 }
                 //again set same character which was manipulated
                 s[i]=c;
                }
               // ans++;
            }
            
        }
        return 0;
    }
};