class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_p,max_p=-1;
        int n=prices.size();
for(int i=0;i<n;)
{
  buy_p=i;
  while(i<n and prices[i]>=prices[buy_p]) 
     {
     max_p=max(max_p,prices[i]-prices[buy_p]);
     i++;
    }
}

return max_p;
    }
};