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
    bool calc(TreeNode* a,TreeNode* b)
    {
        if(!a and !b) return true;
        if(!a or !b or a->val!=b->val) return false;
         
        return calc(a->left,b->right) and calc(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return calc(root->left,root->right);
    }
};