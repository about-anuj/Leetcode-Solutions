class MyCalendar {
public:
    vector<pair<int,int>>cal;
    int ind=0;
    MyCalendar() {
        cal.clear();
    }
    
    bool book(int start, int end) {
        for(auto i:cal){
             if((end>i.first and start<i.second))
                 return false;
        }
        cal.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */