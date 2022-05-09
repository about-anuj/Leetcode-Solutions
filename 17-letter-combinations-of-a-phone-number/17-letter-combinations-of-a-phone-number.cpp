class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>ans;
    void calc(string digits,string s,int i,int n)
    {
       if(i==n) 
       {
           ans.push_back(s);
           return;
       }
        
        for(int j=0;j<mp[digits[i]].size();j++)
        {
            s+=mp[digits[i]][j];
            calc(digits,s,i+1,n);
            s.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
           mp.insert({'2',"abc"});
           mp.insert({'3',"def"});
           mp.insert({'4',"ghi"});
           mp.insert({'5',"jkl"});
           mp.insert({'6',"mno"});
           mp.insert({'7',"pqrs"});
           mp.insert({'8',"tuv"});
           mp.insert({'9',"wxyz"});
        calc(digits,"",0,digits.size());
        return ans;
    }
};