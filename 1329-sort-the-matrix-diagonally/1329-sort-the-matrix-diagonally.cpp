class Solution {
public:
    int n,m;
    void change(int i,int j,vector<vector<int>>&mat)
    {
        priority_queue<int>pq;
        while(i<n and j<m)
            pq.push(mat[i++][j++]);
        
        while(--i>=0 and --j>=0)
        {
            mat[i][j]=pq.top();
            pq.pop();
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        n=mat.size(),m=mat[0].size();
        for(int i=0;i<m;i++)
            change(0,i,mat);
        for(int i=0;i<n;i++)
            change(i,0,mat);
        
        return mat;
    }
};