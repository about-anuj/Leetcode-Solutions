class Bitset {
public:
    string s="",filled="";
int sz=0,cnt1=0;
    int flp=0;
    
    Bitset(int size) {
       for(int i=0;i<size;i++)
       {
           s.push_back('0');
           filled.push_back('1');
       }
        sz=size;
        //cout<<s<<endl;
    }
    
    void fix(int idx) {
      if(s[idx]=='0')
         cnt1++;
        
        s[idx]='1';
       filled[idx]='0';
    }
    
    void unfix(int idx) {
        if(s[idx]=='1')
            cnt1--;
        s[idx]='0';
        filled[idx]='1';
    }
    
    void flip() {
        cnt1=sz-cnt1;
        swap(s,filled);
    }
    
    bool all() {
        return cnt1==sz;
    }
    
    bool one() {
        return cnt1;
    }
    
    int count() {
        return cnt1;
    }
    
    string toString() {
       return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */