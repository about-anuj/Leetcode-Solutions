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
    int ans=0;
    void calc(TreeNode* r,int l,int h)
    {
        if(!r) return;
        if(r->val>=l and r->val<=h) ans+=r->val;
        calc(r->left,l,h);
        calc(r->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        calc(root,low,high);
        return ans;
    }
};