class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),l=1,r=n-2,ans=0;
        int mxr=height[n-1],mxl=height[0];
        while(l<=r){
            if(mxl>mxr)
            {
                if(mxr<height[r])
                    mxr=height[r];
                else
                    ans+=(mxr-height[r]);
                
                r--;
            }
            else
            {
                if(mxl<height[l])
                    mxl=height[l];
                else
                    ans+=(mxl-height[l]);
                l++;
            }
        }
        return ans;
    }
};
           