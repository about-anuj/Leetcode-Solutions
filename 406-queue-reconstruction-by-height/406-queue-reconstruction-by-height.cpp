class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        
        return a[0]>b[0] ;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>ans;
        sort(begin(people),end(people),cmp);
       
        for(auto i:people)
            ans.insert(begin(ans)+i[1],i);

        return ans;
    }
};