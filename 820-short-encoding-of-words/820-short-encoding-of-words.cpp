class trie{
        public:
        bool word=false;
        trie* lis[26]={NULL};
        
        
    };
class Solution {
public:
   int insert(trie* h, string &s)
    {
       trie* cur=h;
        bool anybranch=false;
       for(auto i:s){
           if(!cur->lis[i-'a']){
               anybranch=true;
               cur->lis[i-'a']=new trie();}
           
           cur=cur->lis[i-'a'];
       }
        cur->word=true;
        return anybranch==true?s.size():0;
    }
    
    static bool cmp(string& a, string& b){
        return a.size()>b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
    
        sort(begin(words),end(words),cmp);
        trie* head=new trie();
        int ans=0;
       
        for(auto i:words){
          reverse(begin(i),end(i));
            
          int c=insert(head,i);
            if(c)
                ans+=(c+1);
      }   
        
        return ans;
    }
};