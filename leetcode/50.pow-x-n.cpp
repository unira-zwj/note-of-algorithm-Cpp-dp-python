/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) return 1 / myPow(x, -n);
        if (n == 0) return 1;
        double temp = pow(x, n / 2);
        if (n % 2 == 0){
            return temp * temp;
        }
        return temp * temp * x;
    }
};
// @lc code=end

