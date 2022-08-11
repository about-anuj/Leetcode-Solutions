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
    int tgt;
public:
    void calc(TreeNode* cur,TreeNode* par,int l, int r)
    {
        if(!cur) return ;
        //cout<<cur->val<<" "<<l<<" "<<r<<endl;
        
        
        calc(cur->left,cur,1,0);
        calc(cur->right,cur,0,1);
        //check if it is leaf and equal to tgt
        
        if(!cur->left and !cur->right and cur->val==tgt)
        {
            //if root itself leaf and tgt
            if(l==0 and r==0)
                cur=NULL;
            else if(l==1)
                par->left=NULL;
            else
                par->right=NULL;
            
            return;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        TreeNode* par=NULL;
        this->tgt=target;
        calc(root,par,0,0);
        if(root and !root->left and !root->right and root->val==target) return NULL;
        return root;
    }
};