class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
       // ans.push_back(1);
        for(auto i:nums){
            
           while(1){
               int GCD=__gcd(ans.size()==0?1:ans.back(),i);
               //if coprime then break;
               if(GCD==1){
                   
                   break;
               }
               //else take their LCM
               //LCM*GCD=product of two numbers
               i *= ans.back() / GCD;
               //i*gcd=i*ans.back()
               ans.pop_back();
           } 
            ans.push_back(i);
        }
       return ans;
    }
};