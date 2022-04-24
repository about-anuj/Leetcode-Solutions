class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>in;
       unordered_map<string,vector<int>>avg;
    UndergroundSystem() {
       
    }
    
    void checkIn(int id, string st, int t) {
        in[id]={st,t};
    }
    
    void checkOut(int id, string end, int t2) {
        
        string st=in[id].first;
        int t1=in[id].second;
        string route=st+"_"+end;
        //route,sum,no. of times
        if(avg.count(route)==0)
        {
            avg[route]={(t2-t1),1};
        }
        else{
            avg[route][0]+=(t2-t1);
            avg[route][1]+=1;
        }
    }
    
    double getAverageTime(string st, string end) {
        string route=st+"_"+end;
        return (double) avg[route][0]/avg[route][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */