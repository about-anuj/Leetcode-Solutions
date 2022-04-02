class Solution {
public:
    bool ispalin(string s,int esc)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(l==esc){
                l++;
                continue;
            }
            if(r==esc){
                r--;
                continue;
            }
            
            if(s[l]!=s[r])
                return false;
            
            l++,r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1,c=0,x=0;
        while(l<r)
        {
            if(s[l]==s[r])
                l++,r--;
            
            
          else
            {
             int l1=l,l2=l+1,r1=r-1,r2=r;
              while(l1<r1 and s[l1]==s[r1]) l1++,r1--;
              while(l2<r2 and s[l2]==s[r2]) l2++,r2--;
              
              return l1>=r1 or l2>=r2;
            }
        }
      //  cout<<c;
        return 1;
    }
};