class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans=0;
        f.insert(f.begin(),0);
        f.push_back(0);
        for(int i=1;i<f.size()-1;i++)
        {
            if(f[i-1]==0 and f[i]==0 and f[i+1]==0){
                n--;
            f[i]=1;
        }
        }
        return n<=0;
    }
};