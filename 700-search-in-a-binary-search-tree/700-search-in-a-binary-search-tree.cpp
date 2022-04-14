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

    TreeNode* ans=NULL;
    void srch(TreeNode* root,int val)
    {
         if(root==NULL) return;
        if(root->val==val){ 
            ans=root;
            return;
        }
        if(root->val<val) srch(root->right,val);
        else srch(root->left,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
       srch(root,val);
       return ans;
    }
};