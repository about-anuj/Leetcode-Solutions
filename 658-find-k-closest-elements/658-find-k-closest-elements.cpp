class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0,j=arr.size()-1;
        vector<int>res;
        while(j-i>=k)
        {
            if(abs(arr[i]-x)>abs(arr[j]-x))
                i++;
            else
                j--;
        }
        for(int k=i;k<=j;k++) res.push_back(arr[k]);
        return res;
    }
};