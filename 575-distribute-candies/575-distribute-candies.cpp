class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        
    return min(unordered_set<int>(begin(candy),end(candy)).size(),candy.size()/2);
    }
};