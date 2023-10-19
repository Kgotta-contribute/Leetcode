#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    int n1 = 2;
    cout << "Example 1: " << solution.climbStairs(n1) << endl;

    int n2 = 3;
    cout << "Example 2: " << solution.climbStairs(n2) << endl;

    return 0;
}





// Iteration 1:
// Initialize n to 4.
// Create a vector dp of size 5 (0 to 4) and initialize it with zeros: [0, 0, 0, 0, 0].
// Handle the base cases:
// dp[1] = 1
// dp[2] = 2

// Iteration 2:
// Start a loop from i = 3 to 4.
// Calculate dp[3] = dp[2] + dp[1] = 2 + 1 = 3.

// Iteration 3:
// Calculate dp[4] = dp[3] + dp[2] = 3 + 2 = 5.
// The dp vector after all iterations: [0, 0, 1, 2, 3, 5].

// The final result is dp[4] = 5, which means there are 5 distinct ways to climb to the top with n = 4 steps.
// So, for n = 4, the function returns 5.