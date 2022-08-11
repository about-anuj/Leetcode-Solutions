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
    int prec(TreeNode* r)
    {
        while(r->right) r=r->right;
        return r->val;
    }
    int suc(TreeNode* r)
    {
        while(r->left) r=r->left;
        return r->val;
    }
    bool calc(TreeNode* r)
    {
        if(!r) return true;
        if(r->left and prec(r->left)>=r->val)
            return false;
        if(r->right and suc(r->right)<=r->val)
            return false;
        
        return calc(r->left) and calc(r->right);
    }
    bool isValidBST(TreeNode* root) {
        return calc(root);
    }
};