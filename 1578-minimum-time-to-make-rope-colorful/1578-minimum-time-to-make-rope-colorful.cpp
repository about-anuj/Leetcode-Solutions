class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
       
        int res=0;
        for(int i=0;i<colors.size();)
        {
            char c=colors[i];
            int mn=0,j=i,sm=0;
            while(i<colors.size() and colors[i]==c)
            {
                sm+=needTime[i];
                mn=max(mn,needTime[i]);
                i++;
            }
            //it means there are more duplicates
            if(i-j>1)
            {
                res+=(sm-mn);  //only take minimum number from them
            }
        }
        return res;
    }
};