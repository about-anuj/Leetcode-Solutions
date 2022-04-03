class Solution {
public:
    int convertTime(string current, string correct) {
        int cur,cor,ans=0;
        // string h1,h2,m1,m2;
        // h1=current[0]+current[1];

       
        cur=60*stoi(current.substr(0,2))+stoi(current.substr(3));
        cor=60*stoi(correct.substr(0,2))+stoi(correct.substr(3));
        //cout<<cur<<" "<<cor;
       int d=abs(cur-cor);
        
        return d/60+(d%60)/15+(d%15)/5+d%5;
    }
};