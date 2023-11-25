#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        if (first != -1 && last != -1) {
            return {first, last};
        } else {
            return {-1, -1};
        }
    }

private:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1; // Continue searching on the left side
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return first;
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1; // Continue searching on the right side
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return last;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Example 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Example 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "Example 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Example 3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "Example 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}






// I can provide a step-by-step explanation of how the searchRange function works using numeric iterations. Let's use an example with the sorted array [5, 7, 7, 8, 8, 10] and the target value 8. We'll go through both the findFirst and findLast helper functions as well.
// Step 1: Initialize findFirst
//     • left is initialized to 0.
//     • right is initialized to 5 (the index of the last element).
//     • first is initialized to -1.
// Step 2: First Binary Search Iteration (for findFirst)
//     • Calculate mid as (left + right) / 2 = 2.
//     • Compare nums[mid] (7) with the target (8).
//         ◦ Since 7 < 8, update left to mid + 1 = 3.
// Step 3: Second Binary Search Iteration (for findFirst)
//     • Calculate mid as (left + right) / 2 = 4.
//     • Compare nums[mid] (8) with the target (8).
//         ◦ Found a match. Update first to mid = 4 and continue searching on the left side.
//         ◦ Update right to mid - 1 = 3.
// Step 4: Third Binary Search Iteration (for findFirst)
//     • Calculate mid as (left + right) / 2 = 3.
//     • Compare nums[mid] (8) with the target (8).
//         ◦ Found a match. Update first to mid = 3 and continue searching on the left side.
//         ◦ Update right to mid - 1 = 2.
// Step 5: Fourth Binary Search Iteration (for findFirst)
//     • Calculate mid as (left + right) / 2 = 2.
//     • Compare nums[mid] (7) with the target (8).
//         ◦ Since 7 < 8, update left to mid + 1 = 3.
// Step 6: Fifth Binary Search Iteration (for findFirst)
//     • left (3) is greater than right (2), so exit the loop.
//     • Return first = 3 as the result for findFirst.
// Step 7: Initialize findLast
//     • left is initialized to 0.
//     • right is initialized to 5 (the index of the last element).
//     • last is initialized to -1.
// Step 8: First Binary Search Iteration (for findLast)
//     • Calculate mid as (left + right) / 2 = 2.
//     • Compare nums[mid] (7) with the target (8).
//         ◦ Since 7 < 8, update left to mid + 1 = 3.
// Step 9: Second Binary Search Iteration (for findLast)
//     • Calculate mid as (left + right) / 2 = 4.
//     • Compare nums[mid] (8) with the target (8).
//         ◦ Found a match. Update last to mid = 4 and continue searching on the right side.
//         ◦ Update left to mid + 1 = 5.
// Step 10: Third Binary Search Iteration (for findLast)
//     • left (5) is greater than right (5), so exit the loop.
//     • Return last = 4 as the result for findLast.
// The final result for the searchRange function is [3, 4], indicating that the target value 8 is found starting at index 3 and ending at index 4 in the array [5, 7, 7, 8, 8, 10].