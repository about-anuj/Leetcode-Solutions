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
    map<int,vector<pair<int,int>>>mp;
    bool static cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
    void calc(TreeNode* r,int ind,int l)
    {
        if(!r) return;
        mp[ind].push_back({r->val,l});
        calc(r->left,ind-1,l+1);
        calc(r->right,ind+1,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        calc(root,0,0);
        for(auto i:mp){
            vector<pair<int,int>>v;
            for(auto j:i.second)
                v.push_back(j);
            
           sort(begin(v),end(v),cmp);
            vector<int>t;
            for(auto j:v)
                t.push_back(j.first);
            
            ans.push_back(t);
        }
        return ans;
    }
};