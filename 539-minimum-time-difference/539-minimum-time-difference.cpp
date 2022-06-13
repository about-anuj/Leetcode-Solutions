class Solution {
public:
    int findMinDifference(vector<string>& time) {
       sort(begin(time),end(time));
        int n=time.size();
        int ans=INT_MAX;
        for(int i=0;i<time.size();i++)
        {
            int diff=abs(mindif(time[(i+1)%n],time[i]));
//cout<<diff<<" ";
            diff=min(diff,1440-diff);
            ans=min(ans,diff);
        }
        return ans;
    }
    private:
    int mindif(string& s2, string& s1){
        int h1=stoi(s1.substr(0,2));
        int h2=stoi(s2.substr(0,2));
        int m1=stoi(s1.substr(3,2));
        int m2=stoi(s2.substr(3,2));
        
        return 60*(h2-h1)+m2-m1;
    }
};