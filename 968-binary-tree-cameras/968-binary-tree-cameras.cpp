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
    int calc(TreeNode* root)
    {
        if(!root) return 2;  // leaf
        int left=calc(root->left),right=calc(root->right);
        if(left==0 or right==0)
        {
            ans++;
            return 1; //camera
        }
        
        return left==1 or right==1?2:0;
    }
    int minCameraCover(TreeNode* root) {
     return (calc(root)<1?1:0)+(ans);
    }
};