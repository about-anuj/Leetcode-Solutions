class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1) return true;
        
        if(word[0]>='A' and word[0]<='Z')
        { 
            
            if(word[1]>='A' and word[1]<='Z')
            {
                for(int i=1;i<word.size();i++)
             {
              if(word[i]>='a' and word[i]<='z') return false;
             }
            }
            else{
                 for(int i=1;i<word.size();i++)
                if(word[i]>='A' and word[i]<='Z') return false;
            }
            
            
        }
        
       if(word[0]>='a' and word[0]<='z')
        {
           cout<<"ok";
            for(int i=1;i<word.size();i++)
                if(word[i]>='A' and word[i]<='Z') return false;
        }
        return true;
    }
};