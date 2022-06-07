class TextEditor {
public:
    stack<char>l,r;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto i:text) l.push(i);
    }
    
    int deleteText(int k) {
        int c=0;
        while(k-- and !l.empty())
        {
            l.pop();
            c++;
        }
        return c;
    }
    
    string cursorLeft(int k) {
        while(k-- and !l.empty()){
            r.push(l.top());
            l.pop();
        }
        
        return calc();
    }
    
    string cursorRight(int k) {
        while(k-- and !r.empty()){
            l.push(r.top());
            r.pop();
        }
        
        return calc();
    }
    
    string calc()
    {
       string st="";
       int c=10;
        while(!l.empty() and c--){
            st+=l.top();
            l.pop();
        }
     reverse(begin(st),end(st));
        for(auto i:st)
            l.push(i);
        
        return st;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */