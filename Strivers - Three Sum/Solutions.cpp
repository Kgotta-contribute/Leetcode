#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the input array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test the threeSum function
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    
    // Print the results
    for (const vector<int>& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}



// Input Vector: nums = {-1, 0, 1, 2, -1, -4}

// Sort the Input Array:

// The input vector nums is sorted in ascending order.
// After sorting, nums = {-4, -1, -1, 0, 1, 2}.
// Outer Loop (i):

// The outer for loop iterates through the sorted array from index 0 to n - 2, where n is the size of the array.

// It starts with i = 0 and checks each element in the array.

// Iteration 1 (i = 0):

// i = 0, nums[i] = -4.
// Inner while loop:
// left = 1, right = 5.
// sum = -4 + -1 + 2 = -3 (sum is less than 0, so left is incremented).
// left = 2, right = 5.
// sum = -4 + -1 + 1 = -4 (sum is less than 0, so left is incremented).
// left = 3, right = 5.
// sum = -4 + -1 + 0 = -5 (sum is less than 0, so left is incremented).
// left = 4, right = 5.
// sum = -4 + -1 + -1 = -6 (sum is less than 0, so left is incremented).
// left and right cannot be moved further as left < right is no longer true.
// No valid triplet found for i = 0.
// Iteration 2 (i = 1):

// i = 1, nums[i] = -1.
// Inner while loop:
// left = 2, right = 5.
// sum = -1 + -1 + 2 = 0 (sum equals 0, a valid triplet is found).
// Triplet { -1, -1, 2 } is added to the result.
// Duplicates are skipped, and left and right are updated.
// left = 3, right = 4.
// sum = -1 + 0 + 1 = 0 (sum equals 0, another valid triplet is found).
// Triplet { -1, 0, 1 } is added to the result.
// Iteration 3 (i = 4):

// i = 4, nums[i] = 1.
// Inner while loop:
// left = 5, right = 5.
// sum = 1 + 2 + 2 = 5 (sum is greater than 0, so right is decremented).
// left and right cannot be moved further as left < right is no longer true.
// No valid triplet found for i = 4.
// Result:

// The result vector contains two unique triplets: { -1, -1, 2 } and { -1, 0, 1 }.