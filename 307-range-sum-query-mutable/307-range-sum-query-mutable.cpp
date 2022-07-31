


class NumArray {
public:
    
    int len=0;
    vector<int>sqsm;  //store each square root group sum at one index;
    vector<int>a;
  //public:
    void init(const vector<int>&nums)
    {
        this->a=nums;
        len=ceil(sqrt((int)nums.size()));
        
        sqsm.assign(len,0);
        for(int i=0;i<nums.size();i++)
        {
            sqsm[i/len]+=a[i];
        }
    }
    
    void upd(int index,int val){
        sqsm[index/len]-=a[index];
        sqsm[index/len]+=val;
        a[index]=val;
    }
    
    int calc(int l,int r){
        int sm=0;
        //if both are from same square box then we can iterate through the array
        if(l/len==r/len){
            for(int i=l;i<=r;i++)
                sm+=a[i];
            return sm;
        }
        
        //first and last block that we can access in the square array
        int fstblk=l/len+1,lstblk=r/len-1;
        //first compute left of the partial box if any box is present then all mid boxes then right
        //partial box if any present
        
        while(l/len<fstblk) sm+=a[l++];
        //all mid blocks from square root
        while(fstblk<=lstblk) sm+=sqsm[fstblk++];
        //all right from a array here r+1 is written because r%len will zero and we can't include last element
        while(r/len>lstblk) sm+=a[r--];
        //sm+=a[r];
        return sm;
        
    }
//};

    NumArray(vector<int>& nums) {
        init(nums);
    }
    
    void update(int index, int val) {
        upd(index,val);
    }
    
    int sumRange(int left, int right) {
        return calc(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */