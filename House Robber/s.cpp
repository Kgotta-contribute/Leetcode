#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        
        // Base cases for the first two houses
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Traverse through the remaining houses
        for (int i = 2; i < n; ++i) {
            // Decide whether to rob the current house or not
            // Choose the maximum amount between robbing the current house + money robbed 2 houses before
            // and not robbing the current house (taking maximum from the previous house)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        // Return the maximum amount robbed from the last house
        return dp[n - 1];
    }
};


/*
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/