#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;  // Index for the last element of nums1
        int j = n - 1;  // Index for the last element of nums2
        int k = m + n - 1;  // Index for the merged array

        // Merge elements from the end of both arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1) {
        std::cout << num << " ";
    }

    return 0;
}



// Initialize i to 2 (index for the last element of nums1), j to 2 (index for the last element of nums2), and k to 5 (index for the merged array).

// First iteration of the while loop:

// Compare nums1[i] (3) and nums2[j] (6). Since 6 is greater, assign 6 to nums1[k].
// Update j to 1 and k to 4.
// Updated nums1: [1, 2, 3, 0, 6, 0]
// Second iteration of the while loop:

// Compare nums1[i] (3) and nums2[j] (5). Since 5 is greater, assign 5 to nums1[k].
// Update j to 0 and k to 3.
// Updated nums1: [1, 2, 3, 5, 6, 0]
// Third iteration of the while loop:

// Compare nums1[i] (3) and nums2[j] (2). Since 3 is greater, assign 3 to nums1[k].
// Update i to 1 and k to 2.
// Updated nums1: [1, 2, 3, 5, 6, 3]
// Fourth iteration of the while loop:

// Compare nums1[i] (2) and nums2[j] (2). Since they are equal, assign 2 to nums1[k].
// Update i to 0 and j to -1 (end of nums2).
// Updated nums1: [1, 2, 2, 5, 6, 3]
// Fifth iteration of the while loop:

// j is less than 0, so exit the loop.
// The first while loop has finished, and all elements from both arrays have been merged into nums1. It now looks like this: [1, 2, 2, 3, 5, 6].

// The second while loop checks if there are any remaining elements in nums2. In this case, there are none, so it exits.

// The merged array nums1 is printed to the console:

// 1 2 2 3 5 6