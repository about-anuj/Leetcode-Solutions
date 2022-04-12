class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
               
                int c=0;
                //up
                
                if(i-1>=0 and (board[i-1][j]==1 or board[i-1][j]==3))
                    c++;
                //left
                
                if(j-1>=0 and (board[i][j-1]==1 or board[i][j-1]==3))
                    c++;
                //right
                
                if(j+1<n and (board[i][j+1]==1 or board[i][j+1]==3))
                    c++;
                //down
                if(i+1<m and (board[i+1][j]==1 or board[i+1][j]==3))
                    c++; 
                
                //ur
                if(j+1<n and i-1>=0  and (board[i-1][j+1]==1 or board[i-1][j+1]==3))
                    c++;
               
                //rd
                
                if(j+1<n and i+1<m and (board[i+1][j+1]==1 or board[i+1][j+1]==3))
                    c++;
                //dl
                 
                if(j-1>=0 and i+1<m and (board[i+1][j-1]==1 or board[i+1][j-1]==3))
                    c++;
                //lu
                if(j-1>=0 and i-1>=0 and ( board[i-1][j-1]==1 or board[i-1][j-1]==3))
                    c++;
                
                
                
                if(board[i][j]==1){
                if(c<2 or c>3)
                    board[i][j]=3;  //newly dead
                }
                else if(board[i][j]==0)
                {
                    if(c==3) board[i][j]=2; //newly alive
                }
            }
            
        }
        for(int i=0;i<m;i++)
        { 
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==3) board[i][j]=0;
                if(board[i][j]==2) board[i][j]=1;
            }
        }
    }
};