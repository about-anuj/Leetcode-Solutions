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
    vector<TreeNode*>node;
    vector<int>v;
    void in(TreeNode* r)
    {
        if(!r) return;
        in(r->left);
        v.push_back(r->val);
        node.push_back(r);
        in(r->right);
    }
    int calc(TreeNode* r)
    {
        if(!r) return 0;
        int x=calc(r->left);
        int y=calc(r->right);
        return x+y+r->val;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        in(root);
        int s=calc(root);
        node[0]->val=s;
        for(int i=1;i<v.size();i++)
        {
            node[i]->val=s-v[i-1];
            s-=v[i-1];
        }
        return root;
    }
};