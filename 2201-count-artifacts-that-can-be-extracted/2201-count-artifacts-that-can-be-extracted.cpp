class Solution {
public:
   
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
       int ans=0;
        vector<vector<bool>>mp(n,vector<bool>(n,false));
        for(auto i:dig){
            mp[i[0]][i[1]]=true;
        }
        
        for(auto i:artifacts){
            //define count and total count as 0
           // int c=0,tc=0;
            bool is=false;
            //search all digs 
            for(int x=i[0];x<=i[2];x++){
                for(int y=i[1];y<=i[3];y++)
                {
                    //search
                    if(mp[x][y]==false)
                    {
                        is=true;
                        break;
                    }
                    
                    // c++;
                    // //tc will increase all time
                    // tc++;
                }
                if(is) break;
            }
            
            //if count and total count is equal means all artifact buried so increase answer
            if(!is)
                ans++;
        }
        return ans;
    }
};