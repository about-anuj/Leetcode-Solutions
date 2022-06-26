class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int i=0,j=0,cur=0,mn=INT_MAX;
        int sz=n-k;
        while(j<n){
           if(j-i<sz){
               cur+=cards[j++];
               if(j-i==sz){
                   mn=min(mn,cur);
               }
           } 
            else{
                cur-=cards[i++];
            }
            
        }
        int total=accumulate(begin(cards),end(cards),0);
        return total-mn;
    }
};