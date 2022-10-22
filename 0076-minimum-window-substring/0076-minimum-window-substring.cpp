class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1,m2;
        int back=0,front=0,n=s.size(),res=INT_MAX;
        for(auto i:t) m2[i]++;
        t="";
        while(front<=s.size())
        {
            // cout<<back<<" "<<front<<endl;
            bool cantake=false;
            for(char i='A';i<='z';i++)
            {
                if(m2.count(i) and m1[i]<m2[i])
                {
                    cantake=true;
                }
            }
            
            //need more variables
            if(cantake)
            {
                //if the current variable is present in t
                if(front<s.size() and m2.count(s[front]))
                    m1[s[front]]++;
                front++;
            }
            else
            {
                if(res>front-back)
                {
                    res=front-back;
                    t=s.substr(back,front-back);
                }
                if(m1.count(s[back])) m1[s[back]]--;
                back++;
            }
        }
        return t;
    }
};