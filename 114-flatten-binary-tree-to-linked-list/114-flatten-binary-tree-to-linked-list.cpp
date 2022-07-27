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
    //inorder precessoder
    TreeNode* calc(TreeNode* r){
        while(r->right){
            r=r->right;
        }
        return r;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* t=root;
        while(t){
         
            if(t->left)
            {
               TreeNode* pre=calc(t->left);
                pre->right=t->right;
                t->right=t->left;
                t->left=NULL;
            }
            t=t->right;
        }
     
    }
};