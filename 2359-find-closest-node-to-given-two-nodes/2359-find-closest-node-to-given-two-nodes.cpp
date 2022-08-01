class Solution {
public:
    void dfs(vector<int>edges,int node,vector<int>& memo){
        int dist=0;
        while(node!=-1 and memo[node]==-1)
        {
            memo[node]=dist++;
            node=edges[node];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n=edges.size(),ans_node=-1,min_dist=INT_MAX;
         vector<int>m1(n,-1),m2(n,-1);
         dfs(edges,node1,m1);
         dfs(edges,node2,m2);
        
         for(int i=0;i<edges.size();i++)
         {
             //current node should be reachable from both the nodes
             if(m1[i]>=0 and m2[i]>=0)
             {
                 
                 if(min_dist>max(m1[i],m2[i]))
                 {
                     min_dist=max(m1[i],m2[i]);
                     ans_node=i;
                 }
             }
         }
        return ans_node;
    }
};