#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

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
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int target2 = 2;
    int result1 = solution.search(nums, target1);
    int result2 = solution.search(nums, target2);
    cout << "Result 1: " << result1 << endl; // Output: 4
    cout << "Result 2: " << result2 << endl; // Output: -1
    return 0;
}




// JAVA

import java.util.Arrays;

class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

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
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {-1, 0, 3, 5, 9, 12};
        int target1 = 9;
        int target2 = 2;
        int result1 = solution.search(nums, target1);
        int result2 = solution.search(nums, target2);
        System.out.println("Result 1: " + result1); // Output: 4
        System.out.println("Result 2: " + result2); // Output: -1
    }
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