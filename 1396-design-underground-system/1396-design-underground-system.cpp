class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>in;
       unordered_map<string,pair<int,int>>avg;
    UndergroundSystem() {
       
    }
    
    void checkIn(int id, string st, int t) {
        in[id]={st,t};
    }
    
    void checkOut(int id, string end, int t2) {
        
        string st=in[id].first;
        int t1=in[id].second;
        string route=st+"_"+end;
        
        //route,sum,no. of time
            avg[route].first+=(t2-t1);
            avg[route].second+=1;
        
    }
    
    double getAverageTime(string st, string end) {
        string route=st+"_"+end;
        return (double) avg[route].first/avg[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */