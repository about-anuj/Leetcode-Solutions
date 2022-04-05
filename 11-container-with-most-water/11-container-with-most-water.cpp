class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0,l=0,r=h.size()-1;
        
        while(l<r)
        {
            int area=min(h[l],h[r])*(r-l);
            ans=max(ans,area);
            h[l]<h[r]?l++:r--;
        }
        return ans;
    }
};