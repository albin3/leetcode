// Source: https://leetcode.com/problems/powx-n/
// Author: Albin Zeng
// Date: 2015-06-11

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        if (n>0 && n%2 == 1) return x*myPow(x*x, (n-1)/2);
        if (n<0 && n%2 == -1) return (1/x)*myPow(x*x, (n+1)/2);
        return myPow(x*x, n/2);
    }
};
