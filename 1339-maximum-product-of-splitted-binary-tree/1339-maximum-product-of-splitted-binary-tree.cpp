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
    long long ans=0,sum=0;
    int calc(TreeNode* root)
    {
        if(!root) return 0;
        if(root->left==root->right) return root->val;
        int l=calc(root->left);
        int r=calc(root->right);
        ans=max({ans,l*(sum-l),r*(sum-r)});
        return l+r+root->val;
    }
    void sm(TreeNode* r)
    {
        if(!r) return;
        sum+=r->val;
        sm(r->left);
        sm(r->right);
    }
    int maxProduct(TreeNode* root) {
        sm(root);
        calc(root);
        return ans%1000000007;
    }
};