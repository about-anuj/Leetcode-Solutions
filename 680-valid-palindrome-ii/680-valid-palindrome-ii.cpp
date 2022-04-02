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
            
            
          else if(s[l]!=s[r])
            {
              c++;
              if( (ispalin(s,l) or ispalin(s,r)))
                return true;
              
               if( !(ispalin(s,l) and !ispalin(s,r)))
                   return false;
            }
        }
      //  cout<<c;
        return c<=1;
    }
};