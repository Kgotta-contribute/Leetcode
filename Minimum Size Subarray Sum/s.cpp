
#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLength = std::min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

// int main() {
//     Solution solution;

//     // Example 1
//     int target1 = 7;
//     std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
//     std::cout << "Example 1: " << solution.minSubArrayLen(target1, nums1) << std::endl;

//     // Example 2
//     int target2 = 4;
//     std::vector<int> nums2 = {1, 4, 4};
//     std::cout << "Example 2: " << solution.minSubArrayLen(target2, nums2) << std::endl;

//     // Example 3
//     int target3 = 11;
//     std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
//     std::cout << "Example 3: " << solution.minSubArrayLen(target3, nums3) << std::endl;

//     return 0;
// }
