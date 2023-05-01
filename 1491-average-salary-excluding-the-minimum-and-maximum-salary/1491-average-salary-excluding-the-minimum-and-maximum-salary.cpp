class Solution {
public:
    double average(vector<int>& salary) {
        double sum=accumulate(begin(salary),end(salary),0.0);
        sum-=*max_element(begin(salary),end(salary));
        sum-=*min_element(begin(salary),end(salary));
        return 1.0*(sum/(salary.size()-2));
    }
};