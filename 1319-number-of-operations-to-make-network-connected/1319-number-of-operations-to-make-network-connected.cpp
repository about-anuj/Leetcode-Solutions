//By union find 
//from one cable we can connect two pc it means if we found one redundant 
//connection it means we can connect two parents
//find total number of parents by disjoint set and then 
//find total number of redundant connections if 
//total parents-1<=redundant then we can joint them and
//if cables will less then return -1
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
       
        int redun=0,total=0;
        //assign parent itself
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto i:conn)
        {
            if(find(parent[i[0]])==find(parent[i[1]]))
                redun++;
            else
                make_parent(i[0],i[1]);
        }
        
        //now calculate total number of parent
      for(int i=0;i<n;i++)
          if(parent[i]==i) total++;
        
        //if redundant is greater then equal to parents-1(one row can add two nodes)
        return redun>=total-1?total-1:-1;
    }
    private:
    int parent[100001]={0};
    //to return parent of the child
    int find(int child)
    {
        while(child!=parent[child])
            child=parent[child];
        
        return child;
    }
    //to make parent
    void make_parent(int a,int b)
    {
        a=find(a);
        b=find(b);
        //if parent same then return
        if(a==b) return;
        //if not then make
        parent[a]=b;  //or parent[b]=a;
    }
    
};