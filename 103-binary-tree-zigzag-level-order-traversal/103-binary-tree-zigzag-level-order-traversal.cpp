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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        //for even level go from left to right
        bool even=true;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v;
            while(sz--)
            {
               TreeNode* t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
               
                v.push_back(t->val);
            }
            if(!even){
                reverse(begin(v),end(v));
            }
            ans.push_back(v);
            //change odd to even and vice versa
            if(even) even=false;
            else even=true;
        }
        return ans;
    }
};