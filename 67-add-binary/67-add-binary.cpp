class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        int sz=min(a.length(),b.length());  // this is maximum iteration we can done in loop
        int last=max(a.length(),b.length());  //last point to start addition
        int x=a.length()-1,y=b.length()-1;
        for(int i=0;i<sz;i++)
        {
            if(a[x]=='1' and b[y]=='1')
            {
                if(!carry)
                    ans='0'+ans;
                else
                    ans='1'+ans;
               carry=1;
            }
            else if(a[x]=='0' and b[y]=='0')
            {
                if(carry){
                    ans='1'+ans;
                carry=0;
                }
                else
                    ans='0'+ans;
            }
            else{
                if(carry)
                    ans='0'+ans;
                else
                    ans='1'+ans;
            }
           // cout<<ans<<endl;
            x--,y--;
        }
       
        string s=(x==-1?b:a);
        last=max(x,y);
        
        for(;last>=0;last--)
        {
            if(carry)
            {
                if(s[last]=='1'){
                ans='0'+ans;
                }
                else
                  {
                    ans='1'+ans;
                   carry=0;
                }
                
            }
            else{
                if(s[last]=='0')
                    ans='0'+ans;
                else
                    ans='1'+ans;
            }
            
        }
        if(carry)
            ans='1'+ans;
        return ans;
    }
};