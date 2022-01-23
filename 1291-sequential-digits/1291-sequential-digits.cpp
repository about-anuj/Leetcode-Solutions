class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
       queue<int>q;
        vector<int>ans;
        for(int i=1;i<=9;i++)
         q.push(i);
        
        while(!q.empty())
        {
            int cur=q.front(); q.pop();
            if(cur>h) break;
            if(cur>=l and cur<=h) ans.push_back(cur);
            int num=cur%10;
            int c=cur*10+(num+1);
            if(num<9) q.push(c);
        }
        return ans;
    }
};