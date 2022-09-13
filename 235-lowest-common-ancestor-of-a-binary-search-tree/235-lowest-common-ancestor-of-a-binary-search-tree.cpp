/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if(!r) return NULL;
        if(r==p) return r;
        if(r==q) return r;
        
        TreeNode* a=NULL,*b=NULL;
        a=lowestCommonAncestor(r->left,p,q);
        b=lowestCommonAncestor(r->right,p,q);
        
        if(a and b) return r;
        if(!a) return b;
        else return a;
    }
};