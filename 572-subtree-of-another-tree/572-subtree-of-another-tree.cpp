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

    bool fn(TreeNode* a,TreeNode* b)
    {
        if(!a and !b) return true;
        if((!a and b) or (a and !b) or a->val!=b->val) return false;
        return fn(a->left,b->left) and fn(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* t=q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                
                if(t->val==subRoot->val)
                {
                    if(fn(t,subRoot)) return 1;
                }
            }
        }
        return 0;
    }
};