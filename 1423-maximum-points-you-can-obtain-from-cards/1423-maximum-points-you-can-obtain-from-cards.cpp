class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int j=n-k,i=0;
        
        int cur=accumulate(begin(cards)+j,end(cards),0);
        int ans=INT_MIN;
        while(j<=n)
        {
            ans=max(ans,cur);
            if(j==n) break;
            cur-=cards[j++];
            cur+=cards[i++];
        }
        return ans;
    }
};