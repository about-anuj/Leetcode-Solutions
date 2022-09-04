class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& tra) {
        for(int i=1;i<tra.size();i++) tra[i]+=tra[i-1];
        int res=0;
        vector<int>last(128,0);
        for(int i=0;i<gar.size();i++)
        {
            res+=gar[i].size();
            for(auto j:gar[i]) last[j]=i;
        }
        
        for(auto i:"MPG")
        {
            if(last[i])
                res+=tra[last[i]-1];
        }
        return res;
    }
};