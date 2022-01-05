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
    int mx(vector<int>&nums,int i, int j)
    {
        int ind=i;
        for(int k=i;k<=j;k++)
        {
            if(nums[ind]<nums[k])
                ind=k;
        }
        return ind;
    }
    TreeNode* make(vector<int>&nums,int i,int j)
    {
        if(i>j) return NULL;
         int ind=mx(nums,i,j);
        TreeNode* newnode=new TreeNode(nums[ind]);
        newnode->left=make(nums,i,ind-1);
        newnode->right=make(nums,ind+1,j);
        
        return newnode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return make(nums,0,nums.size()-1);
    }
};