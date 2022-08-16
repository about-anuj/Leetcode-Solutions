class Solution {
public:
   bool sub=true;
void isisland(vector<vector<int>>& g1, vector<vector<int>>& g2,int i,int j,int m,int n)
{
 if(i<0 or i>=m or j<0 or j>=n or g2[i][j]==2 or g2[i][j]==0) return;
 if(g2[i][j]==1 and g1[i][j]==0) {
 	sub=false;
 	return;
 }
  g2[i][j]=2;
 isisland(g1,g2,i+1,j,m,n);
 isisland(g1,g2,i,j+1,m,n);
 isisland(g1,g2,i,j-1,m,n);
 isisland(g1,g2,i-1,j,m,n);
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
{
     int m=grid2.size(),n=grid2[0].size(),ans=0;
     for(int i=0;i<m;i++)
     {
     	for(int j=0;j<n;j++)
     	{
     		if(grid2[i][j]==1)
     		{
     			sub=true;
     			isisland(grid1,grid2,i,j,m,n);
     			if(sub){
                  //  cout<<i<<" "<<j<<endl;
     				ans++;}
     		}
     	}
     }   
    // for(auto i:grid2)
    // {
    //     for(auto j:i)
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
     return ans;
}
};