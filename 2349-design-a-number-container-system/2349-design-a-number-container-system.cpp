class NumberContainers {
public:
    unordered_map<int,int>ind_num;
    unordered_map<int,set<int>>num_inds;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind_num.count(index)){
            int prevnum=ind_num[index];
            //remove from last map
            num_inds[prevnum].erase(index);
            ind_num[index]=number;
            num_inds[number].insert(index);
        }
        else{
            ind_num[index]=number;
            num_inds[number].insert(index);
        }
    }
    
    int find(int number) {
        if(num_inds[number].size()>0)
         return *num_inds[number].begin();
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */