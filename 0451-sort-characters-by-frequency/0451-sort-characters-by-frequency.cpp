class Solution {
public:
    string frequencySort(string s) {
        vector<int>a(26,0),b(26,0),c(10,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' and s[i]<='z')
                a[s[i]-'a']++;
            else if(s[i]>='A' and s[i]<='Z')
                b[s[i]-'A']++;
            else
                c[s[i]-'0']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++)
        {
            if(a[i])
                pq.push({a[i],'a'+i});
            if(b[i])
                pq.push({b[i],'A'+i});
            if(i<10 and c[i])
                pq.push({c[i],'0'+i});
        }
        s.erase();
        while(!pq.empty())
        {
            int sz=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(sz--)
                s+=ch;
            
        }
        return s;
    }
};