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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(!root) return NULL;
        if(depth==2)
        {
            TreeNode* x=root->left,*y=root->right;
            TreeNode* nl=new TreeNode(val),*nr=new TreeNode(val);
            root->left=nl;
            root->right=nr;
            nl->left=x;
            nr->right=y;
            return root;
        }
        else if(depth==1)
        {
            TreeNode* t=new TreeNode(val);
            t->left=root;
            return t;
        }
        TreeNode* l=addOneRow(root->left,val,depth-1);
        TreeNode* r=addOneRow(root->right,val,depth-1);
        return root;
    }
};