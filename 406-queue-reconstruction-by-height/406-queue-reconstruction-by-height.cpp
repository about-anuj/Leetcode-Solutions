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
       
        // for(auto i:people)
        //     cout<<i[0]<<" "<<i[1]<<endl;
        
        for(int i=0;i<people.size();i++)
        {
            if(people[i][1]==ans.size())
                ans.push_back(people[i]);
            else
                ans.insert(begin(ans)+people[i][1],people[i]);
        }
        return ans;
    }
};