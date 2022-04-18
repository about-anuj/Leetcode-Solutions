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
    int c,ans;
    bool find=false;
    void calc(TreeNode* r)
    {
        if(!r or find) return ;
        calc(r->left);
        
        c--;
        if(c==0){
          ans=r->val;
            find=true;
            return;
        }
        calc(r->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        c=k;
        calc(root);
       return ans; 
    }
};