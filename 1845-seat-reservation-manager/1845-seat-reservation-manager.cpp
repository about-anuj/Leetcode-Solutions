class SeatManager {
public:
    set<int>unres;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            unres.insert(i);
    }
    
    int reserve() {
        int x=*begin(unres);
        unres.erase(x);
        return x;
    }
    
    void unreserve(int seatNumber) {
        unres.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */