class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>>range;
        vector<bool>vis(26,false);
       for(auto i:s) 
       {
           if(!vis[i-'a'])
           {
           int j=0;
           int first=-1,last=-1;
           vis[i-'a']=true;
           for(int j=0;j<s.size();j++)
           {
               //if same element is encountered then find its first and last index
               if(s[j]==i)
               {
                if(first<0)
                 {
                   first=j;
                   last=j;
                 }
                else
                 last=j;
               }
              
           }
                range.push_back({first,last});
           }
       }
//         for(auto i:range)
//             cout<<i[0]<<" "<<i[1]<<endl;
        
        vector<vector<int>>diff;
        diff.push_back(range[0]);
        for(int i=1;i<range.size();i++)
        {
            vector<int>check=diff.back();
            //if previous range cover current range completely
            if(check[1]>range[i][1])
                continue;
            //if prev range covers partially then just increase prev range
            if(check[1]>range[i][0])
            {
                diff.pop_back();
                diff.push_back({check[0],range[i][1]});
            }
            
            //if they are entirely diffferent then just push
            else
                diff.push_back(range[i]);
        }
     vector<int>res;
        for(auto i:diff)
        {
            res.push_back(i[1]-i[0]+1);
        }
        return res;
    }
};