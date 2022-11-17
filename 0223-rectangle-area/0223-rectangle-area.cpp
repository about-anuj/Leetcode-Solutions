class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x[]={ax1,bx1,ax2,bx2};
        int y[]={ay1,by1,ay2,by2};
        sort(x,x+4);
        sort(y,y+4);
        int total=(abs((ax2-ax1)*(ay2-ay1))+abs((bx2-bx1)*(by2-by1)));
        
        //no overlapping
        if(ax2<=bx1 or ax1>=bx2 or ay1>=by2 or ay2<=by1) return total;
        
        return total-(x[2]-x[1])*(y[2]-y[1]);
    }
};