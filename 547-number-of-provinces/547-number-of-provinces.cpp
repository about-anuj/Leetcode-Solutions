class Solution {
public:
    int parent[201];
   
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
       //make their parent same
        for(int i=0;i<mat.size();i++)
                 parent[i]=i;
        
        //if their parent is same then ok otherwise increase answer;
        int ans=n;
      
        for(int i=0;i<mat.size();i++)
        {
         for(int j=i+1;j<mat.size();j++)
         {
             if(mat[i][j])
             {
                 int p1=find(i);
                 int p2=find(j);
                 if(p1!=p2)
                 {
                     parent[p1]=p2;
                     ans--;
                 }
             }
         }
        }
        return ans;
    }
    private:
    int find(int i)
    {
        while(i!=parent[i])
            i=parent[i];
        
        return i;
    }
};