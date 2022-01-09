class Solution {
public:
    bool isRobotBounded(string ins) {
        bool n=true,s=false,e=false,w=false;
        int x=0,y=0;
        for(int i=0;i<4;i++){
        for(auto i:ins)
        {
            if(i=='G')
            {
                if(n)
                    y++;
                else if(w)
                    x--;
                else if(s)
                    y--;
                else
                    x++;
            }
            else if(i=='R')
            {
                if(n)
                {
                    n=false;
                    e=true;
                }
                else if(w)
                {
                    n=true;
                    w=false;
                }
                else if(e)
                {
                    e=false;
                    s=true;
                }
                else{
                    s=false;
                    w=true;
                }
                    
            }
            else{
                if(n)
                {
                    n=false;
                    w=true;
                }
                else if(e)
                {
                    e=false;
                    n=true;
                }
                else if(w)
                {
                    w=false;
                    s=true;
                }
                else
                {
                    s=false;
                    e=true;
                }
            }
        }
        }
        if(x==0 and y==0) return 1;
        //if(n) return 0;
        return 0;
    }
};