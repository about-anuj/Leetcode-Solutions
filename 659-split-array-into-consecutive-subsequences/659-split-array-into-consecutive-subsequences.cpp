class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        
        //we have to check that before starting new subsequence can current element join a 
        //already formed subsequence or it need to create new
        unordered_map<int,int>left,end;
        for(auto i:nums) left[i]++;
        for(auto i:nums)
        {
            if(!left[i]) continue;
            
            left[i]--;
            //can it join existed subsequence
            if(end[i-1]>0){
                end[i-1]--;
                end[i]++;
            }//if not than can it create new subsequence of atleast three element including itself
            else if(left[i+1] and left[i+2])
            {
                //we have added next two element so exclude them from left 
                left[i+1]--;
                left[i+2]--;
                end[i+2]++; //ending of list is at i+2 
            }
            else //if cant join or cant make then it is not possible to add that element to any list
                return false;
            
        }
        return true;
    }
};