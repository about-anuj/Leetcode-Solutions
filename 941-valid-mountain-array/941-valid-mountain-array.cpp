class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       
       int i=0;
        int n=size(arr);
        while(i+1<n and arr[i]<arr[i+1]) i++;
        
        if(i==0 or i==n-1) return 0;
        
        while(i+1<n and arr[i]>arr[i+1]) i++;
        
        return i==n-1;
    }
};