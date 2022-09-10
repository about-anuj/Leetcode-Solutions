class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_p=0,res=0,n=prices.size();
        for(int i=1;i<n;i++)
        {
           if(prices[buy_p]>prices[i]) buy_p=i;
          else
          {
            res+=(prices[i]-prices[buy_p]);
            buy_p=i;
          } 
        }
        return res;
    }
};