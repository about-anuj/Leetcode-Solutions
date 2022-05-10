class Solution {
public:
    vector<vector<int>>ans;
    void calc(int k, int n, int cur,vector<int>&v,int sum)
    {
        if(k==0)
        {
            if(accumulate(begin(v),end(v),0)==n)
              ans.push_back(v);
            else
                return;
        }
        
        if(cur>9 ) return ;
        v.push_back(cur); //include cur
        calc(k-1,n,cur+1,v,sum);
        v.pop_back();   //not include cur
        calc(k,n,cur+1,v,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>v;
        //for(int i=1;i<=9;i++)
        calc(k,n,1,v,0);
        sort(begin(ans),end(ans));
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};