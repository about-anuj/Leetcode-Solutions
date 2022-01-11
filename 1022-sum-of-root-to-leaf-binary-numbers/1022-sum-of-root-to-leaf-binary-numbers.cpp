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
    int ans=0;
    string s;
    void calc(TreeNode* r, string cur)
    {
        if(!r) return;
        if(r and !r->left and !r->right)
        {
            cur.push_back(r->val+'0');
            int c=0,i=0;
            while(cur.size()>0)
            {
               if((cur.back())=='1')
                   c+=pow(2,i);
                cur.pop_back();
                i++;
            }
            ans+=c;
            
            return;
        }
        
        cur.push_back(r->val+'0');
        calc(r->left,cur);
        calc(r->right,cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<char>v;
        calc(root,"");
        return ans;
    }
};