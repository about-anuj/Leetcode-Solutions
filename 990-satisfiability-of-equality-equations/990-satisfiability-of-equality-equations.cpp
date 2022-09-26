class Solution {
public:
    int dsu[26];
    int find_parent(int c)
    {
        // char org=c;
        while(dsu[c]!=c)
           c=dsu[c];
        
        // cout<<c<<" ";
        return c;
    }
    bool equationsPossible(vector<string>& eq) {
        // dsu.resize(26,0);
        //set parent as same
        for(auto i='a';i<='z';i++) dsu[i-'a']=i-'a';
        
        for(auto i:eq)
        {
            if(i[1]=='=')
            {
                int x=find_parent(i[0]-'a');
                int y=find_parent(i[3]-'a');
                //set parent
                dsu[x]=y;
            }
        }
        // for(auto i:dsu)cout<<i<<" ";
        for(auto i:eq)
        {
            if(i[1]=='!')
            {
                int x=find_parent(i[0]-'a');
                int y=find_parent(i[3]-'a'); 
                if(x==y) return 0;
            }
                
        }
        return 1;
    }
};