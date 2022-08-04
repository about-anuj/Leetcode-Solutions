class Solution {
    int k;
public:
    vector<vector<int>>ans;
    vector<int>v;
    void calc(int j,int k,int n)
    {
        if(k==0)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i=j;i<=n;i++)
        {
                v.push_back(i);
                calc(i+1,k-1,n);
                v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        calc(1,k,n);
        return ans;
        
    }
};