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
class BSTIterator {
public:
    vector<int>v;
    int i=0;
    void calc(TreeNode* r)
    {
        if(!r) return;
        calc(r->left);
        v.push_back(r->val);
        calc(r->right);
    }
    BSTIterator(TreeNode* root) {
        calc(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<(int)v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */