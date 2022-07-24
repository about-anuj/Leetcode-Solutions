struct comp {
 bool operator()(const pair<int, string> &a, const pair<int, string> &b) const 
    { 
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};

class FoodRatings {
public:
    map<string, int> m1; 
    map<string, set<pair<int, string>, comp>> m2;
    map<string, string> temp;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n=f.size();
        for(int i=0; i<n; i++)
        {
            m1[f[i]]=r[i];
            m2[c[i]].insert({r[i], f[i]});
            temp[f[i]]=c[i];
        }
    }
    
    void changeRating(string f, int nr) {
        m2[temp[f]].erase({m1[f], f});
        m2[temp[f]].insert({nr, f});
        m1[f]=nr;
    }
    
    string highestRated(string cuisine) {
        return (*m2[cuisine].begin()).second;
    }
};