class Solution {
public:
	void dfs(vector<vector<string>>&ans,unordered_map<string,vector<string>>&mp,string &src,vector<string>&v,string dest)
	{
     // cout<<src<<" ";
      if(src==dest)
      {
      	ans.push_back(v);
      	//cout<<endl;
      	return;
      }
      for(auto i:mp[src])
      {
      	v.push_back(i);
      	dfs(ans,mp,i,v,dest);
      	v.pop_back();
      }
	}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        int step=0;
        bool find=false;
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>vis;
        unordered_set<string>st(wordList.begin(), wordList.end());
        st.insert(beginWord);
        queue<string>q;
        q.push(beginWord);
        //cur level is 0
        vis[beginWord]=0;
        while(!q.empty())
        {
        	int sz=q.size();
        	while(sz--)
        	{
        	string cur=q.front();
        	q.pop();
        	if(cur==endWord)
        		find=true;
             for(int i=0;i<cur.size();i++)
             {
             	string t=cur;
             	for(char c='a';c<='z';c++)
             	{
             		if(c==t[i]) continue;

             		cur[i]=c;
                    if(st.count(cur))
                    {
                    	//cout<<cur<<" ";
                      if(!vis.count(cur))
                      {
                      	vis[cur]=vis[t]+1;  //level increases
                      	q.push(cur);
                      	mp[cur].push_back(t);
                      }
                      else if(vis[cur]-1==vis[t])
                      	mp[cur].push_back(t);
                    }
             	}

             	cur=t;
             } 
//cout<<endl;
            }
            if(find) break;
            //cout<<endl;
            step++;
        }

        
        vector<string>temp;
        dfs(ans,mp,endWord,temp,beginWord);
        for(auto &i:ans)
        {
          	reverse(begin(i),end(i));
          	i.push_back(endWord);

        }
        return ans;
    }
};