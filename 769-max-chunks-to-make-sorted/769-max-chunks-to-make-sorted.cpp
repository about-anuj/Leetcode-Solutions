class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int s=0,ans=0,arrsum=0;
        for(int i=0;i<arr.size();i++){
            s+=i;
            arrsum+=arr[i];
            if(s==arrsum)
                ans++;
        }
        return ans;
    }
};