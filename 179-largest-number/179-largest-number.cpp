
class Solution {
public:
    bool static cmp(int a, int b){
        if(to_string(a)+to_string(b)>to_string(b)+to_string(a))
            return true;
        return 0;
    }
    string largestNumber(vector<int>& nums) {
       sort(begin(nums),end(nums),cmp);
        string res="";
        for(auto i:nums)
            res+=to_string(i);
        
        while(res.length()>1 and res[0]=='0' )
            res.erase(0,1);
        
        return res;
    }
};