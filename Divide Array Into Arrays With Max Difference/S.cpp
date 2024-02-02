#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Initialize the result vector
        vector<vector<int>> result;
        
        // Iterate through the array and divide it into arrays of size 3
        for (int i = 0; i < n; i += 3) 
        {
            // Check if the current subarray satisfies the conditions
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) 
            {
                // Add the subarray to the result
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } 
            else 
            {
                // If conditions are not satisfied, return an empty array
                return {};
            }
        }
        
        return result;
    }
};
