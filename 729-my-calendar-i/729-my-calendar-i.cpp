class MyCalendar {
public:
    map<int,int>cal;
    int ind=0;
    MyCalendar() {
        cal.clear();
    }
    
    bool book(int start, int end) {
       auto it=cal.upper_bound(start);
        if(it!=cal.end() and end>it->first)
            return 0;
        if(it!=cal.begin() and prev(it)->second>start)
            return 0;
        cal[start]=end;
        return 1;
    }
};

/**end>
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */