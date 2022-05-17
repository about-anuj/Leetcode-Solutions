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
  
    TreeNode* ans=NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(!original) return NULL;
        if(original==target){
            ans=cloned;
            return ans;
        }
        TreeNode* l=getTargetCopy(original->left,cloned->left,target);
        TreeNode* r=getTargetCopy(original->right,cloned->right,target);
        
        return ans;
    }
};