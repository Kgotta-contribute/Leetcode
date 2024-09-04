// JAVA
class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if the middle element is the target
            if (nums[mid] == target) {
                return true;
            }
            
            // The tricky part is dealing with duplicates
            // If nums[left], nums[mid], and nums[right] are all the same, we cannot determine which side is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {  // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Target is in the left sorted part
                } else {
                    left = mid + 1;   // Target is in the right part
                }
            } else {  // Right side must be sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is in the right sorted part
                } else {
                    right = mid - 1; // Target is in the left part
                }
            }
        }
        
        return false;  // Target is not found
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Example 1
        int[] nums1 = {2, 5, 6, 0, 0, 1, 2};
        int target1 = 0;
        System.out.println("Search result for target " + target1 + ": " + sol.search(nums1, target1));  // Output: true
        
        // Example 2
        int[] nums2 = {2, 5, 6, 0, 0, 1, 2};
        int target2 = 3;
        System.out.println("Search result for target " + target2 + ": " + sol.search(nums2, target2));  // Output: false
    }
}





// CPP
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespae std;

bool searchInRotatedSortedArrayII(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
            // Handle duplicates at both ends
            left++;
            right--;
        } else if (arr[left] <= arr[mid]) {
            // Left half is sorted

            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted

            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return false; // Target not found
}

int main() {
    vector<int> arr1 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target1 = 3;

    bool result1 = searchInRotatedSortedArrayII(arr1, target1);
    cout << "Result: " << boolalpha << result1 << "\n";

    vector<int> arr2 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target2 = 10;

    bool result2 = searchInRotatedSortedArrayII(arr2, target2);
    cout << "Result: " << boolalpha << result2 << "\n";

    return 0;
}
