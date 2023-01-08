class Solution {
public:
    float slope(float x1, float y1, float x2, float y2)
    {
        if(x2 - x1 != 0)
         return (y2 - y1) / (x2 - x1);
      
        return INT_MAX*1.0;
    }
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size(),res=0;
        unordered_map<float,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(i==j) continue;
                float x1=p[i][0];
                float y1=p[i][1];
                float x2=p[j][0];
                float y2=p[j][1];
                
               mp[slope(x1,y1,x2,y2)]++;
            }
            for(auto i:mp)
            res=max(i.second,res);
            
            mp.clear();
        }
        
        
        //self point was not included
        return res+1;
        
    }
};