/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       vector<vector<int>>ans; 
        if(!root) 
         return ans;
        vector<int>v;
        v.push_back(root->val);
        ans.push_back(v);
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            v.clear();
            while(sz--)
            {
                Node* t=q.front();
                q.pop();
                for(auto i:t->children)
                {
                    v.push_back(i->val);
                    q.push(i);
                }
            }
           if(v.size()>0) ans.push_back(v);
        }
        return ans;
    }
};