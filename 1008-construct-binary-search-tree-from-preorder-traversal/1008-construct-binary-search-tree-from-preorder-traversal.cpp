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
    int ind=0;
    TreeNode* bstFromPreorder(vector<int>& pre,int b=INT_MAX) {
        if(ind==pre.size()) return NULL;
        if(pre[ind]>b) return NULL;
            
            int cur=pre[ind++];
            TreeNode* t=new TreeNode(cur);
            t->left=bstFromPreorder(pre,cur);
            t->right=bstFromPreorder(pre,b);
        return t;
    }
};