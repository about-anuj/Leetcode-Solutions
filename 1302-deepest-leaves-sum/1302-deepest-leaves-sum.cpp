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
    int getDepthOfTree(TreeNode* root){
        if(!root) return 0;
        return 1+max(getDepthOfTree(root->left), getDepthOfTree(root->right));
    }
    int deepestLeavesSum(TreeNode* root, int level){
        if(!root) return 0;
        if(level==1) return root->val;
        return deepestLeavesSum(root->left,level-1) + deepestLeavesSum(root->right,level-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth(getDepthOfTree(root));
        return deepestLeavesSum(root,depth);
    }
};