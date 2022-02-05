class Solution {
public:
    //finding answer of every possible minute that equal to targetSecond
    int solve(vector<int> &a,int sa, int mc, int pc){
        int ans = 0;
        if(a[0] != sa){
            ans += mc;
        }
        ans += pc;
        for(int i=1;i<a.size();i++){
            if(a[i] != a[i-1]){
                ans += mc;
            }
            ans += pc;
            
        }
        return ans;
    }
    
    int minCostSetTime(int sa, int mc, int pc, int ts) {
        int cost = 1e8;
        //trying all permutation
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                int h = i*10+j;
                for(int k=0;k<=9;k++){
                    for(int l=0;l<=9;l++){
                        vector<int> ans;
                        int m = h*60 + k*10 + l;
                        if(m == ts){
                            ans.emplace_back(i);
                            ans.emplace_back(j);
                            ans.emplace_back(k);
                            ans.emplace_back(l);
                            cost = min(cost,solve(ans,sa,mc,pc));
                             while(ans[0] == 0){
                                 ans.erase(ans.begin());
                                 cost = min(cost,solve(ans,sa,mc,pc));
                             }
                        }
                    }
                }
            }
        }
        return cost;
    }
};
