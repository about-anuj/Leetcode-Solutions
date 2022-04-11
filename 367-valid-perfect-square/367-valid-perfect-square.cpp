class Solution {
public:
    bool isPerfectSquare(int num) {
        int x=pow(num,0.5);
        return x*x==num;
    }
};