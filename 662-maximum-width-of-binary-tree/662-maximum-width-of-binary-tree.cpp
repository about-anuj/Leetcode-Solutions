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
        queue<pair<TreeNode*,unsigned int >>q;
        q.push({root,0});
        unsigned int ans=0;
        while(!q.empty())
        {
           unsigned  int end=q.back().second,st=q.front().second;
           unsigned  int sz=q.size();
            ans=max(ans,end-st+1);
           // cout<<ans<<endl;
            while(sz--)
            {
              TreeNode* t=q.front().first;
              unsigned int ind=q.front().second-st;
             // cout<<ind<<" ";
              q.pop();
              
              if(t->left) q.push({t->left,2*ind+1});
              if(t->right) q.push({t->right,2*ind+2});
            }
            cout<<endl;
        }
        return ans;
    }
};