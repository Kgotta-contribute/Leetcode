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



// std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
// int target = 9;
// Here's how the code progresses step by step:

// Initial values:

// left = 0 (index of the first element)
// right = 5 (index of the last element)
// mid = (0 + 5) / 2 = 2 (middle index)
// nums[mid] = nums[2] = 3 (middle element)
// First iteration:

// 3 is not equal to 9, so we move to the next step.
// Since 3 is less than 9, we update left to mid + 1, so left becomes 3.
// Second iteration:

// left = 3
// right = 5
// mid = (3 + 5) / 2 = 4 (new middle index)
// nums[mid] = nums[4] = 9 (middle element)
// We found the target 9, so we return mid, which is 4.