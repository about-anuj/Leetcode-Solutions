class Solution {
public:
    int maximumSwap(int num) {
       string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            char x='0';
            int ind;
            for(int j=i+1;j<s.size();j++)
            {
               if(x<=s[j])
               {
                   x=s[j];
                   ind=j;
               }
            }
            if(x>s[i]){
                swap(s[i],s[ind]);
                break;
            }
                
        }
        return stoi(s);
    }
};