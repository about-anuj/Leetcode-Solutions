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
    int ans=INT_MIN;
    int calc(TreeNode* r)
    {
        if(!r) return 0;
        int l=calc(r->left);
        int rr=calc(r->right);
        ans=max({ans,r->val+l+rr,r->val+l,r->val+rr,r->val});
        return max({r->val+l,r->val+rr,r->val});
    }
    int maxPathSum(TreeNode* root) {
         calc(root);  
        return ans;
    }
};