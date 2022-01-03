class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>num;
        for(int i=0;i<bank.size();i++)
        {
            int c=0;
            for(auto j:bank[i])
            {
             if(j=='1')
                 c++;
            }
            if(c!=0) num.push_back(c);
        }
        int ans=0;
        for(int i=1;i<size(num);i++)
        {
            ans+=(num[i]*num[i-1]);
        }
        return ans;
    }
};