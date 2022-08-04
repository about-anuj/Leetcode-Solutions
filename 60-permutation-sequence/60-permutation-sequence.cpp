class Solution {
    string ans="";
    int k;
public:
    
    void calc(int n,string &s,unordered_set<int>&st,string temp)
    {
        if(k==0)
        {
            return;
        }
        if(temp.size()==n)
        {
            this->ans=temp;
            k--;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                st.insert(i);
                temp+=s[i];
                calc(n,s,st,temp);
                st.erase(i);
                temp.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        string s="";
        int factorial=1;
        for(int i=1;i<n;i++)
            factorial*=i;
        
        //this is edge case
        // if(factorial==k)
        // {
        //     for(int i=n;i>=1;i--) s+=i+'0';
        //         return s;
        // }
       
        //choose starting point from which digit
        //the res string will start
        this->k=0;
        if(k%factorial==0){
            this->k=1;
            k--;
        }
        
        int start=k/factorial+1;
        s+=start+'0';
        
        //ultimate position as we inserted first character
        this->k+=k%factorial;
        
        for(int i=1;i<=n;i++) 
            if(i!=start) 
                s+=i+'0';
        
     //   cout<<s<<" ";
        unordered_set<int>st;
        vector<int>v;
        calc(n,s,st,"");
        return this->ans;
    }
};