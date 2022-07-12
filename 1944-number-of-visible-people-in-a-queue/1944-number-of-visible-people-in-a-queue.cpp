class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;  //height,index
        //we will start from last and and will store elements in stack in sorted order
        vector<int>res(heights.size(),0);
        for(int i=heights.size()-1;i>=0;i--)
        {
               int visible=0;
               while(!st.empty() and st.top()<heights[i])
                  visible++,st.pop();
            
              //if stack is not empty it means that person can view the person which is in the stack
               if(st.size()>0) visible++;         
               res[i]=visible; 
               st.push(heights[i]);
        }
        return res;
    }
};