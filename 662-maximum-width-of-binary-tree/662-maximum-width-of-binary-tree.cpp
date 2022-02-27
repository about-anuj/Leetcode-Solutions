/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
             unsigned long long   int ans=0,mod=1e9+7;
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,1});
        
        //BFS
        while(!q.empty()){
          unsigned long long   int sz=q.size();
          unsigned long long   int l=q.front().second,r=1;
            while(sz--){
                TreeNode* temp=q.front().first;
                r=q.front().second;
                q.pop();
                
                if(temp->left)
                    q.push({temp->left,(2*r)});
                if(temp->right)
                    q.push({temp->right,(2*r)+1});
            }
            ans=max(ans,r-l+1);
        }
        return (int)ans;
    }
};