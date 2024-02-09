#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // Initializing a vector to store minimum squares needed for each number from 0 to n
        // creates a vector with n + 1 elements, and each element is initialized to INT_MAX, which is a 
        //constant representing the maximum value an int can hold. This means initially, all elements of the vector dp are set to INT_MAX.
        vector<int> dp(n + 1, INT_MAX);
        
        // Base case: 0 requires 0 squares
        dp[0] = 0;
        
        // Loop through each number from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Loop through each perfect square less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update dp[i] with the minimum of current value and dp[i - j*j] + 1
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp[n];
    }
};

/*
Set dp[0] = 0

    dp = [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

Dynamic Programming Loop:

    For i = 1:
        Inner loop:
            For j = 1, since 1 * 1 <= 1, update dp[1] = min(dp[1], dp[1 - 1*1] + 1) = min(INT_MAX, dp[0] + 1) = min(INT_MAX, 0 + 1) = min(INT_MAX, 1) = 1.

    dp = [0, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

    For i = 2:
        Inner loop:
            For j = 1, since 1 * 1 <= 2, update dp[2] = min(dp[2], dp[2 - 1*1] + 1) = min(INT_MAX, dp[1] + 1) = min(INT_MAX, 1 + 1) = min(INT_MAX, 2) = 2

dp = [0, 1, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

    For i = 3:
        Inner loop:
            For j = 1, since 1 * 1 <= 3, update dp[3] = min(dp[3], dp[3 - 1*1] + 1) = min(INT_MAX, dp[2] + 1) = min(INT_MAX, 2 + 1) = min(INT_MAX, 3) = 3

dp = [0, 1, 2, 3, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

    For i = 4:
        Inner loop:
            For j = 1, since 1 * 1 <= 4, update dp[4] = min(dp[4], dp[4 - 1*1] + 1) = min(INT_MAX, dp[3] + 1) = min(INT_MAX, 3 + 1) = min(INT_MAX, 4) = 4.
            For j = 2, since 2 * 2 <= 4, update dp[4] = min(dp[4], dp[4 - 2*2] + 1) = min(4, dp[0] + 1) = min(4, 0 + 1) = min(4, 1) = 1

dp = [0, 1, 2, 3, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

    For i = 5:
        Inner loop:
            For j = 1, since 1 * 1 <= 5, update dp[5] = min(dp[5], dp[5 - 1*1] + 1) = min(INT_MAX, dp[4] + 1) = min(INT_MAX, 1 + 1) = min(INT_MAX, 2) = 2.
            For j = 2, since 2 * 2 <= 5, update dp[5] = min(dp[5], dp[5 - 2*2] + 1) = min(2, dp[1] + 1) = min(2, 1 + 1) = min(2, 2) = 2

    dp = [0, 1, 2, 3, 1, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

        The process continues in a similar manner until dp[12] is calculated.

    Return:
        The function returns dp[12], which is dp[n], i.e., the least number of perfect squares that sum up to n.

In this example, dp[12] = 3, meaning that the least number of perfect squares needed to sum up to 12 is 3 (which is 4 + 4 + 4).
*/