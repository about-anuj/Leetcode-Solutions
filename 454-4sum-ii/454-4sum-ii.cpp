class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        int n=n1.size(),ans=0;
        unordered_map<int,int>m1,m2;
        //iterate in first two loops
        for(auto i:n1)
        {
            for(auto j:n2)
            {
                m1[i+j]++;
            }
        }
        
        //iterate in 3rd and 4th loop
        for(auto i:n3)
        {
            for(auto j:n4)
            {
                m2[i+j]++;
            }
        }
        
        // check how much time summation of both map becomes zero
        //and total ways will x*y
        //let two map has values map has
        // 0, 4, -4, 0
        // 0, 4, -4, 0
        // now first zero in first map has two ways and 
        // second zero in first map also has two ways 
        // total combination are 2*2=4 so multiply both values 
        //same thing done in below code
        for(auto i:m1)
        {
           // cout<<ans<<" ";
            int x=-1*(i.first);
            if(m2.count(x)>0)
                ans+=(i.second*m2[x]); //if map contain value then multiply
            
        }
        return ans;
    }
};