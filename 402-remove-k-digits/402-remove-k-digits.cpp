class Solution {
public:
    string removeKdigits(string num, int k) {
        //make ans string s
        string s="";
        for(auto i:num)
        {
         // while current number is less
            //it means we are on peak so pop that 
            //element from string from back
            while(s.size() and s.back()>i and k)
            {
                k--;
                s.pop_back();
            }
            
            //if i is not zero or stack is not empty then push 
            //element into stack
            //bcz if size were zero and stack was empty then
            //it will cause leading zeroes
            if(s.size() or i!='0')
                s.push_back(i);
        }
        
        while(s.size() and k--)
            s.pop_back();
        
        return s.size()==0?"0":s;
    }
};