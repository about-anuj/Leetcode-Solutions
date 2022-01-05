class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;
        vector<int>ans;
        for(int i=0;i<n;i++)
            temp.push_back(to_string(i+1));
        
        sort(begin(temp),end(temp));
        for(int i=0;i<n;i++)
            ans.push_back(stoi(temp[i]));
        
        return ans;
    }
};