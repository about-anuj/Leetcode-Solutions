class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int ind=max_element(begin(arr),end(arr))-begin(arr);
        //cout<<arr[ind];
        if(ind ==0 or ind==arr.size()-1) return 0;
        for(int i=1;i<=ind;i++)
            if(arr[i]<=arr[i-1])
                return false;
        
        cout<<1;
        for(int i=ind+1;i<arr.size();i++)
            if(arr[i]>=arr[i-1])
                return false;
        
        return 1;
    }
};