class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int tgt) {
        int m=a.size(),n=a[0].size();
        int l=0,r=m*n-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
           int temp= a[mid/n][mid%n];
            
            if(temp==tgt) return 1;
            
            if(temp>tgt)
                r=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
};