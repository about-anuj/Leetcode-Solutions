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
    TreeNode* r=NULL,*last;
    void set(TreeNode* t)
    {
        if(!r){
            r=new TreeNode(t->val);
            last=r;
            return;
        }
        
       last->right=new TreeNode(t->val);
       last=last->right;
    }
    void in(TreeNode* root)
    {
        if(!root) return ;
        in(root->left);
        set(root);
        in(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        in(root);
        return r;
    }
};