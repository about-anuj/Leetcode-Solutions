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
    vector<int>v;
    void in(TreeNode* r)
    {
        if(!r) return ;
        in(r->left);
        v.push_back(r->val);
        in(r->right);
    }
    int minDiffInBST(TreeNode* root) {
        in(root);
        int n=v.size(),ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                else
                ans=min(ans,abs(v[i]-v[j]));
            }
        }
        return ans;
    }
};