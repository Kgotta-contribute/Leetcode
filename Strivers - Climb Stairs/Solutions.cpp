#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n; // There are n ways for n <= 2
        }
        
        int dp[n + 1];
        dp[1] = 1; // There is only 1 way to climb 1 step
        dp[2] = 2; // There are 2 ways to climb 2 steps
        
        for (int i = 3; i <= n; i++) {
            // The number of ways to climb to step i is the sum of ways to reach step (i-1) and step (i-2)
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    Solution solution;
    int ways = solution.climbStairs(n);

    std::cout << "The number of distinct ways to climb " << n << " steps is: " << ways << std::endl;

    return 0;
}
