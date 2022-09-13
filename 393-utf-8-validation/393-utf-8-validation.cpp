class Solution {
public:
    int utf8(int x)
    {
        int one=0,utf=8;
            while(utf--)
            {
                if(x%2!=0)
                    one++;
                else
                    one=0;
                x/=2;
            }
        
        return one;
    }
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        for(int i=0;i<n;)
        {
            int one=0,utf=8;
            one=utf8(data[i++]);
            cout<<one<<" ";
            //one is the utf bit
            if(one==1 or one>4) 
                return false;
            if(one==0) 
            {
                continue;
            }
            int j;
            while(--one and i<n)
            {
                int x=utf8(data[i++]);
              if(x!=1){
                  cout<<x<<" ";    
                  return 0;
              }
            }
            if(one>0) return false;
        }
        return 1;
    }
};