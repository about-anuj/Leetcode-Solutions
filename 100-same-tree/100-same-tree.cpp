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
    bool calc(TreeNode* p,TreeNode* q)
    {
        if(!p and !q) return true;
        if(!p or !q or p->val!=q->val) return false;
        return calc(p->left,q->left) and calc(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return calc(p,q);
    }
};