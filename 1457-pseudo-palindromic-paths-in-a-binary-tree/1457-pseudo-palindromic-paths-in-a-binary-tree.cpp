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
    unordered_map<int,int>mp;
    int ans=0;
    bool check()
    {
        int indi=0,len=0;
        for(auto i:mp)
        {
            if(i.second>0 and i.second%2!=0) indi++;
            len+=i.second;
        }
        if(len%2!=0 and indi>1) return false;
        if(len%2==0 and indi>0) return false;
        return true;
    }
    void in(TreeNode* r)
    {
        if(!r) return;
        if(r->left==r->right)
        {
            mp[r->val]++;
            if(check()) ans++;
            mp[r->val]--;
            return;
        }
        mp[r->val]++;
        in(r->left);
        in(r->right);
        mp[r->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       in(root);
        return ans;
    }
};