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
    TreeNode* n1=NULL,*n2,*prev=new TreeNode(INT_MIN);
public:
    void in(TreeNode* r)
    {
        if(!r) return;
        in(r->left);
        if(!n1 and prev->val>r->val) n1=prev;
        if(n1 and prev->val>r->val) n2=r;
        prev=r;
        
        in(r->right);
    }
    void recoverTree(TreeNode* root) {
        in(root);
        swap(n1->val,n2->val);
    }
};