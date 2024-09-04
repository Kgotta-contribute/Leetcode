// JAVA
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine which side is properly sorted
            if (nums[left] <= nums[mid]) {  // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Target is in the left side
                } else {
                    left = mid + 1;   // Target is in the right side
                }
            } else {  // Right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is in the right side
                } else {
                    right = mid - 1; // Target is in the left side
                }
            }
        }
        
        return -1;  // Target is not found
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Example 1
        int[] nums1 = {4, 5, 6, 7, 0, 1, 2};
        int target1 = 0;
        System.out.println("Index of target " + target1 + ": " + sol.search(nums1, target1));  // Output: 4
        
        // Example 2
        int[] nums2 = {4, 5, 6, 7, 0, 1, 2};
        int target2 = 3;
        System.out.println("Index of target " + target2 + ": " + sol.search(nums2, target2));  // Output: -1
        
        // Example 3
        int[] nums3 = {1};
        int target3 = 0;
        System.out.println("Index of target " + target3 + ": " + sol.search(nums3, target3));  // Output: -1
    }
}





// CPP
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            // Left half is sorted

            if (arr[left] <= target && arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted

            if (arr[mid] < target && arr[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2, 3};
    int target1 = 0;

    int result1 = searchInRotatedSortedArray(arr1, target1);
    cout << "Result: " << result1 << "\n";

    vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;

    int result2 = searchInRotatedSortedArray(arr2, target2);
    cout << "Result: " << result2 << "\n";

    return 0;
}


//EASIER & O9n) time complexity
// #include <iostream>
// #include <vector>

// int searchInRotatedArray(const vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); ++i) {
//         if (nums[i] == target) {
//             return i; // Found the target element at index i
//         }
//     }
//     return -1; // Element not found in the array
// }

// int main() {
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     int target = 0;

//     int result = searchInRotatedArray(nums, target);

//     if (result != -1) {
//         cout << "Element " << target << " found at index " << result << endl;
//     } else {
//         cout << "Element not found in the array." << endl;
//     }

//     return 0;
// }
