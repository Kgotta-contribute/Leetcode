#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);  // Initialize an array to store the length of LIS ending at each index.

        int maxLIS = 1;  // Initialize the maximum LIS to 1 (a single element).

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};

    int result1 = solution.lengthOfLIS(nums1);
    int result2 = solution.lengthOfLIS(nums2);
    int result3 = solution.lengthOfLIS(nums3);

    cout << "Example 1: " << result1 << endl;  // Output: 4
    cout << "Example 2: " << result2 << endl;  // Output: 4
    cout << "Example 3: " << result3 << endl;  // Output: 1

    return 0;
}
