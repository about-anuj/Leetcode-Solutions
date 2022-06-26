class Solution {
public:
    bool is(vector<int>&pos,int gape,int total){
        int prev=pos[0];
        total--;
        for(int i=1;i<pos.size();i++)
        {
            if(pos[i]-prev>=gape){
                total--;
                prev=pos[i];
            }
        }
        return total<1;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(begin(pos),end(pos));
        int i=0,j=*max_element(begin(pos),end(pos));
        while(i<=j){
            int mid=(i+j)/2;
            if(is(pos,mid,m)){
                i=mid+1;
            }
            else
                j=mid-1;
        }
        return j;
    }
};