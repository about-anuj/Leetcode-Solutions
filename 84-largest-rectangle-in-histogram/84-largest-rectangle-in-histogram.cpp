class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       
        int n=heights.size(),ans=0;
        //to store index of next and prev greater element
        vector<int>r(n,0),l(n,0);
        set_r(r,n,heights);
        set_l(l,n,heights);
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(r[i]-l[i]-1)*heights[i]);
         //   cout<<l[i]<<" "<<r[i]<<endl;
        }
        return ans;
    }
    private:
    void set_l(vector<int>&l,int n,vector<int>&heights){
        stack<int>st;
        st.push(0);
        l[0]=-1;
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 and heights[i]<=heights[st.top()])
                st.pop();
            
            if(st.empty())
                l[i]=-1;
            else
                l[i]=st.top();
            st.push(i);
        }
    }
    
    void set_r(vector<int>&r,int n,vector<int>&heights)
    {
        stack<int>st;
        r[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
             while(st.size()>0 and heights[i]<=heights[st.top()]) st.pop();
            
            if(st.empty())
                r[i]=n;
            else
                r[i]=st.top();
            st.push(i);
        }
    }
};