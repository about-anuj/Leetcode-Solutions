class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r)
        {
            int mid=floor((r-l)/2+l),count=0;
           // cout<<mid<<endl;
            for(int i=0;i<n;i++)
            {
              count+=upper_bound(begin(matrix[i]),end(matrix[i]),mid)-begin(matrix[i]);
                //cout<<count<<" ";
            }
           // cout<<endl;
           // if(count==k) return mid;
            if(count<k) l=mid+1;
            else
                r=mid;
        }
        return l;
    }
}; 