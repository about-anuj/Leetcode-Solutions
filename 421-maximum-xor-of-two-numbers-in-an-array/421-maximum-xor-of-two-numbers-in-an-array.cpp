class trie{
public: 
    trie* next[2];
};
class Solution {
public:
   trie* root=new trie();
    void make_tr(int num)
    {
           trie* t=root;
    for(int j=31;j>=0;j--)
       {
            int bit=(num>>j) & 1;
            if(!t->next[bit]) t->next[bit]=new trie();
            t=t->next[bit];

       }     
    }

    int max_xor(int num)
    {
        int ans=0;
        trie* t=root;
        for(int i=31;i>=0;i--)
        {
          bool bit=(num>>i) & 1;
          if(t->next[!bit])
          {
            ans+=pow(2,i);
            t=t->next[!bit];
          }
          else
            t=t->next[bit];
        }
       // cout<<ans<<endl;
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto i:nums)
        {
            make_tr(i);
        }
        for(auto i:nums)
        {
            ans=max(ans,max_xor(i));
        }
        return ans;
    }
};