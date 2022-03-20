class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>total,mtop,mbottom;
        int ans=INT_MAX;
        //store frequency of all elements
        for(auto i:tops) total[i]++,mtop[i]++;
        for(auto i:bottoms) total[i]++,mbottom[i]++;
        
        for(auto i:total)
        {
            //if frequency is less than 6 means it is impossible to make 
            //that element in each row
            if(i.second>=(int) tops.size())
            {
                bool can=true;
                for(int j=0;j<tops.size();j++)
                {
                    if(tops[j]==i.first or bottoms[j]==i.first)
                        continue;
                    
                    can=false;
                    break;
                }
                //set ans as min of ans and least of frequencies of top and bottom of that value and
                //if there are multiple occurance than subtract that occurances
            if(can)
            {
                cout<<mtop[i.first]<<" "<<mbottom[i.first]<<" "<<total[i.first]-(int) tops.size()<<endl;
                ans=min(ans,min(mtop[i.first],mbottom[i.first])-(total[i.first]-(int) tops.size()));
            }
        }
            
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};