class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        vector<int>v;
        for(auto i:ops)
        {
            if(i=="C")
            {
                v.pop_back();
                
            }  
            else if(i=="D")
            {
                v.push_back(2*v.back());
            }
            else if(i=="+")
            {
                v.push_back(v.back()+v[v.size()-2]);
            }
            else{
                v.push_back(stoi(i));
            }
        }
        return accumulate(begin(v),end(v),0);
    }
};