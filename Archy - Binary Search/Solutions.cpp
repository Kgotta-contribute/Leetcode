#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle index.

            if (nums[mid] == target) {
                return mid; // Target found, return its index.
            } else if (nums[mid] < target) {
                left = mid + 1; // Adjust the left boundary.
            } else {
                right = mid - 1; // Adjust the right boundary.
            }
        }

        return -1; // Target not found in the array.
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int target2 = 2;

    int result1 = solution.search(nums, target1);
    int result2 = solution.search(nums, target2);

    std::cout << "Result 1: " << result1 << std::endl; // Output: 4
    std::cout << "Result 2: " << result2 << std::endl; // Output: -1

    return 0;
}
