class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        int n=l.size();
        for(int i=0;i<n;i++){
            vector<int>v(begin(nums)+l[i],begin(nums)+r[i]+1);
            sort(begin(v),end(v));
            
            // for(auto j:v)
            //     cout<<j<<" ";
            
            bool is=true;
            int n1=v.size();
            for(int j=1;j<n1-1;j++)
            {
                
                if(2*v[j]!=v[j-1]+v[j+1]){
                    is=false;
                    break;
                }
            }
          //  cout<<endl;
            ans.push_back(is);
        }
        return ans;
    }
};