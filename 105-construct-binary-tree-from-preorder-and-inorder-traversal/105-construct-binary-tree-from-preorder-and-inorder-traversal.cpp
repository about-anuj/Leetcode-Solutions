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
    int preind=0;
    TreeNode* calc(vector<int>&pre, vector<int>&in, int i, int n){
        //no node
        if(i>n)
            return NULL;
        
        //find index in inorder array then split preorder in left and right according to inorder
        TreeNode* root=new TreeNode(pre[preind++]);
        int ind=find(in.begin(), in.end(), root->val)-begin(in);
        //split in left
        root->left=calc(pre,in,i,ind-1);
        //split in right
        root->right=calc(pre,in,ind+1,n);
      //return
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return calc(preorder,inorder,0,preorder.size()-1);
    }
};