#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& arr)
{
    int left = 0, right = arr.size() - 1, ans = INT_MAX;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        //search space is already sorted like left half is sorted & right half is sorted in another way
        if(arr[left] <= arr[right])
        {
            ans = min(ans, arr[left]);
            break;
        }
        //if left part is sorted
        if(arr[left] <= arr[mid])
        {
            ans = min(ans, arr[left]);
            //eliminate the left half
            left = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            //eliminate the right half
            right = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int ans = findMin(arr);
    cout<<"The minimum element is : "<<ans << "\n";
    return 0;
}



// OR 



#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than the last element,
            // the minimum element must be in the right subarray.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // If mid element is less than or equal to the last element,
            // the minimum element must be in the left subarray.
            else {
                right = mid;
            }
        }

        // Left will be pointing to the minimum element.
        return nums[left];
    }
};

int main() {
    Solution solution;

    //  1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    int result1 = solution.findMin(nums1);
    cout << " 1: " << result1 << endl;

    //  2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int result2 = solution.findMin(nums2);
    cout << " 2: " << result2 << endl;

    //  3
    vector<int> nums3 = {11, 13, 15, 17};
    int result3 = solution.findMin(nums3);
    cout << " 3: " << result3 << endl;

    return 0;
}









//     • We initialize left to 0 and right to the last index of the array.
//     • We use a binary search loop to find the minimum element by comparing the middle element (mid) with the last element (nums[right]).
//     • If nums[mid] is greater than nums[right], it means the minimum element is in the right subarray, so we update left to mid + 1.
//     • If nums[mid] is less than or equal to nums[right], it means the minimum element is in the left subarray, so we update right to mid.
//     • The loop continues until left and right converge to the minimum element.
// This code has a time complexity of O(log n) due to binary search, making it an efficient solution for finding the minimum element in a rotated sorted array.

// Can you provide numeric iterations of this code just like how the websites like pythontutor.com provides to show you the iteration at each step for longestPallindrome
// ChatGPT
// Certainly! I'll provide numeric iterations to demonstrate how the findMin function works using binary search on the example [3, 4, 5, 1, 2].
// Step 1: Initialize left to 0 and right to 4 (last index).
// Step 2: First Binary Search Iteration
//     • Calculate mid as (left + right) / 2 = 2.
//     • Compare nums[mid] (5) with nums[right] (2).
//         ◦ Since 5 > 2, update left to mid + 1 = 3.
// Step 3: Second Binary Search Iteration
//     • Calculate mid as (left + right) / 2 = 3.
//     • Compare nums[mid] (1) with nums[right] (2).
//         ◦ Since 1 < 2, update right to mid = 3.
// Step 4: Third Binary Search Iteration
//     • Calculate mid as (left + right) / 2 = 3.
//     • Compare nums[mid] (1) with nums[right] (1).
//         ◦ Since 1 <= 1, update right to mid = 3.
// Step 5: Exit the Binary Search Loop
//     • left (3) is equal to right (3), so exit the loop.
// The final result is nums[3], which is 1. Therefore, the minimum element in the rotated sorted array [3, 4, 5, 1, 2] is 1.