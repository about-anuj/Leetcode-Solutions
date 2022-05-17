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
    bool find=false;
    TreeNode* ans=NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(!original) return NULL;
        
         if(find) return ans;
        
        if(original==target){
            find=true;
            ans=cloned;
            return ans;
        }
        TreeNode* l=getTargetCopy(original->left,cloned->left,target);
        TreeNode* r=getTargetCopy(original->right,cloned->right,target);
        
        return ans;
    }
};