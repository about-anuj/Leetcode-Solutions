class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        int x=a.length()-1,y=b.length()-1;
        while(x>=0 or y>=0)
        {
            int sum=carry;
            sum+=(x>=0?a[x--]-'0':0);
            sum+=(y>=0?b[y--]-'0':0);
            
            ans=to_string(sum%2)+ans;
            carry=sum/2;
        }
        if(carry) ans="1"+ans;
        return ans;
    }
};