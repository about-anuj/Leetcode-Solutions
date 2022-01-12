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
    void calc(TreeNode* root, TreeNode* prnt, TreeNode* newnode)
    {
        if(!root)
        {
            if(prnt->val<newnode->val)
                prnt->right=newnode;
            else
                prnt->left=newnode;
            return;
        }
        if(newnode->val<root->val) calc(root->left,root,newnode);
        else calc(root->right,root,newnode);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if(!root) return newnode;
        calc(root,root,newnode);
        return root;
    }
};