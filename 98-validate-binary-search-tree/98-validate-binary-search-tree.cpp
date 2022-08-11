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
    bool calc(TreeNode* r,long mn,long mx)
    {
        if(!r) return true;
        if(mn>=r->val)
            return false;
        if( mx<=r->val)
            return false;
        
        return calc(r->left,mn,r->val) and calc(r->right,r->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return calc(root,LONG_MIN,LONG_MAX);
    }
};

// bool isValidBST(TreeNode* root) {
//         return help(root, LONG_MIN, LONG_MAX);
//     }
    
//     bool help(TreeNode* root, long min, long max){
//         if(!root)   return true;
//         if(root->val <= min || root->val >= max)  return false;
//         return help(root->left, min, root->val) && help(root->right, root->val, max);
//     }