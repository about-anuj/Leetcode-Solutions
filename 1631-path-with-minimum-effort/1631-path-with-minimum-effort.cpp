class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int n=heights.size(),m=heights[0].size();
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
       //dist,i,j
        pq.push({0,0,0});
       // vis[0][0]=1;
        dp[0][0]=0;
        int ans=INT_MAX;
        while(!pq.empty())
        {
            vector<int>v=pq.top(); pq.pop();
            int d=v[0],x=v[1],y=v[2];
           
           // cout<<v[0]<<" "<<v[1]<<v[2]<<endl;
            if(x==n-1 and y==m-1) return d;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
               
                if(nx>=0 and nx<n and ny>=0 and ny<m ){
                //vis[nx][ny]=1;
                int diff= max(d,abs(heights[x][y]-heights[nx][ny]));
                    if(diff<dp[nx][ny]){
                        dp[nx][ny]=diff;
                        pq.push({diff,nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};