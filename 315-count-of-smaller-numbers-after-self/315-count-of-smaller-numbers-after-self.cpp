class Solution {
public:
    
    
    void merge(vector<pair<int,int>>&vp,int st,int mid,int en,vector<int>&ans){
        vector<pair<int,int>>temp(en-st+1);
        int i=st,j=mid+1,k=0;
        
        while(i <= mid and j <= en){
            if(vp[i].first <= vp[j].first){
                temp[k++] = vp[j++];
            }else{
                ans[vp[i].second] += en - j + 1;
                temp[k++] = vp[i++];
            }
        }
        while(i <= mid) temp[k++] = vp[i++];
        while(j <= en) temp[k++] = vp[j++];
        
        i=st;
        while(i<=en) vp[i++] = temp[i - st];
        
    }
    void mergesort(vector<pair<int,int>>&nums,int i,int j,vector<int>&ans){
        if(i<j){
        int mid=i+(j-i)/2;
        mergesort(nums,i,mid,ans);
        mergesort(nums,mid+1,j,ans);
        merge(nums,i,mid,j,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        vector<pair<int,int>>v;
        int j=0;
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],i});
        
        mergesort(v,0,nums.size()-1,ans);
        return ans;
    }
};