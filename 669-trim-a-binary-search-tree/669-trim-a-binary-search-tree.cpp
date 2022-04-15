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
    queue<TreeNode*>q,temp;
   bool done;
    void fill(TreeNode* r, TreeNode* t)
    {
        if(done or !r) return;
        if(!r->left and t->val<r->val) {
            r->left=t;
            done=true;
            return ;
        }
        if(!r->right and t->val>r->val)
        {
            r->right=t;
            done=true;
            return;
        }
        
        if(r->val>t->val)
        fill(r->left,t);
        else
        fill(r->right,t);
    }
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* t=q.front();
                q.pop();
                
                if(t->val>=l and t->val<=h) temp.push(t);
                    
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        
        if(temp.size()==0) return NULL;
        TreeNode* r=temp.front();
         temp.pop();
        r->left=r->right=NULL;
       while(!temp.empty())
       {
           
           done=false;
           TreeNode* t=temp.front();
           temp.pop();
           
           t->left=t->right=NULL;
           fill(r,t);
       }
        return r;
    }
};