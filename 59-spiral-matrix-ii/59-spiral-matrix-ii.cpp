class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
       vector<vector<int>>v(n,vector<int>(n,0));
        int l=0,t=0,b=n-1,r=n-1,j=1;
        while(l<=r and t<=b)
        {
            //->
            for(int i=l;i<=r;i++)
              v[t][i]=j++;

              t++;
            //down
            for(int i=t;i<=b;i++)
            v[i][r]=j++;

            r--;

            //<-
            for(int i=r;i>=l;i--)
            v[b][i]=j++;

            b--;
            //upward
            for(int i=b;i>=t;i--)
            v[i][l]=j++;
            l++;  
        }
        return v;
    }
    
    
};