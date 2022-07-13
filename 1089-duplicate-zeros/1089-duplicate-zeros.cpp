class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>v=arr;
        int j=0,i=0;
        while(j<arr.size()){
            if(arr[i]==0){
                v[j++]=0;
                if(j<arr.size()) 
                    v[j++]=0;
                i++;
            }
            else
                v[j++]=arr[i++];
        }
        arr=v;
    }
};