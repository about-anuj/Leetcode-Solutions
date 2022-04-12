class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>v=board;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
               
                int c=0;
                //up
                
                if(i-1>=0 and board[i-1][j]==1)
                    c++;
                //left
                
                if(j-1>=0 and board[i][j-1]==1)
                    c++;
                //right
                
                if(j+1<n and board[i][j+1]==1)
                    c++;
                //down
                if(i+1<m and board[i+1][j]==1)
                    c++; 
                
                //ur
                if(j+1<n and i-1>=0  and board[i-1][j+1]==1)
                    c++;
               
                //rd
                
                if(j+1<n and i+1<m and board[i+1][j+1]==1)
                    c++;
                //dl
                 
                if(j-1>=0 and i+1<m and board[i+1][j-1]==1)
                    c++;
                //lu
                if(j-1>=0 and i-1>=0 and board[i-1][j-1]==1)
                    c++;
                
                
                
                if(board[i][j]==1){
                if(c<2 or c>3 ) v[i][j]=0;
                else v[i][j]=1;
                }
                else
                {
                    if(c==3) v[i][j]=1;
                }
            }
        }
        board=v;
    }
};