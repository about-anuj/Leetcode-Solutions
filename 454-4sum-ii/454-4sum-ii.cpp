class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        int n=n1.size(),ans=0;
        unordered_map<int,int>m1,m2;
        for(auto i:n1)
        {
            for(auto j:n2)
            {
                m1[i+j]++;
            }
        }
        
        for(auto i:n3)
        {
            for(auto j:n4)
            {
                m2[i+j]++;
            }
        }
        
        for(auto i:m1)
        {
            //cout<<i.first<<" ";
            cout<<ans<<" ";
            int x=-1*(i.first);
            if(m2.count(x)>0)
                ans+=(i.second*m2[x]);
            
        }
        return ans;
    }
};