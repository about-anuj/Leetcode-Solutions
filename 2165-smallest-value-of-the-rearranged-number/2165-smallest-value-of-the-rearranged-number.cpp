class Solution {
public:
    long long smallestNumber(long long num) {
    if(num==0) return 0;
      string s;
      int c=0;
      bool neg=false;
      if(num<0) {neg=true;
            num*=-1;
            }
      
      while(num)
      {
        int x=num%10;
        if(x==0)
        {
            c++;
            num/=10;
            continue;
        }
        s.push_back(x+'0');
        num/=10;
      }
       
       sort(begin(s),end(s));
       if(neg)
       {
        reverse(begin(s),end(s));
        while(c--) s.push_back('0');
        long long a=stoll(s);
        cout<<a;
        return -1*a;
       }
       else{
        while(c--) s.insert(s.begin()+1,'0');
        long long a=stoll(s);
        cout<<a;
        return a;
       }
    }
};