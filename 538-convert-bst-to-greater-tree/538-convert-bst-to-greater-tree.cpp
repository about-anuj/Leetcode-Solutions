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
   int s=0;
    void calc(TreeNode* r)
    {
        if(!r) return;
        calc(r->right);
        s+=r->val;
        r->val=s;
        calc(r->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        //if(!root) return root;
        calc(root);
        return root;
    }
};