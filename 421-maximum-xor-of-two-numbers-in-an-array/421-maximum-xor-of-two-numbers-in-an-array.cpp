class Solution {
public:
    struct trie{
        trie* next[2];
    };
    int findMaximumXOR(vector<int>& v) {
        trie* root=new trie();
        int ans=0;
        for(auto i:v)
        {
            int arr[32]={0};
            int c=31;
            int x=i;
            while(x)
            { 
             arr[c--]=x%2;
                x/=2;
            }
            trie* t=root;
            for(int j=0;j<32;j++)
            {
                if(!t->next[arr[j]]) t->next[arr[j]]=new trie();
                t=t->next[arr[j]];
            }
        }
        for(auto j:v)
        {
            int bit[32]={0};
            int x=j;
            int c=31,temp=0;
            trie* t=root;
            while(x)
            {
                bit[c]=x%2;
                x/=2;
                //cout<<bit[c]<<" ";
                c--;
            }
            
            for(int i=0;i<32;i++)
            {
                if(t->next[abs(1-bit[i])]!=NULL)
                {
                    temp+=pow(2,31-i);
                    //cout<<bit[i]<<" ";
                    t=t->next[abs(1-bit[i])];
                }
                else 
                    t=t->next[bit[i]];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};