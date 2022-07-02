class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        int mod=1e9+7;
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);
        sort(begin(hor),end(hor));
        sort(begin(ver),end(ver));
        long long d1=0,d2=0;
        for(int i=0;i<hor.size()-1;i++) d1=max(d1,(long long)(hor[i+1]-hor[i]));
        for(int i=0;i<ver.size()-1;i++) d2=max(d2,(long long)(ver[i+1]-ver[i]));
       
        return ((d1%mod)*(d2%mod))%mod;
    }
};