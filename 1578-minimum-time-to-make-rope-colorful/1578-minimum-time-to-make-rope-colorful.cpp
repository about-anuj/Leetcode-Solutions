class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
       
        int res=0;
        for(int i=0;i<colors.size();)
        {
            char c=colors[i];
            int mx=0,j=i,sm=0;
            //find out total sum and release all element except max element
            while(i<colors.size() and colors[i]==c)
            {
                sm+=needTime[i];
                mx=max(mx,needTime[i]);
                i++;
            }
            //it means there are more duplicates
            if(i-j>1)
            {
                res+=(sm-mx);  //only take maximum number from them it will help to decrease overall cost
            }
        }
        return res;
    }
};