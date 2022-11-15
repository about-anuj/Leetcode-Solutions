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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* r=root,*l=root;
        int hr=0,hl=0;
        while(r) r=r->right,hr++;
        while(l) l=l->left,hl++;
        
        if(hr==hl) return pow(2,hr)-1;
        int x=countNodes(root->left);
        int y=countNodes(root->right);
        return x+y+1;
    }
};