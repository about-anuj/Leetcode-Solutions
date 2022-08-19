class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
         string  t="";
         for(int i=0;i<path.size();i++)
         {
         	string temp="";
         	while(i<path.size() and path[i]!='/') temp+=path[i++];
         	if(temp==".." and !st.empty()) st.pop();
            if(temp!="." and temp!="" and temp!="..") //continue;
            st.push(temp);
         } 
        if(st.empty()) return "/";
         while(!st.empty()){
         	t='/'+st.top()+t;
             st.pop();
         }
         return t;
    }
};