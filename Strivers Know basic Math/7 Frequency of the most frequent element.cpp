#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int left = 0;
        long long totalCost = 0;
        int maxFrequency = 1;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Calculate the cost to make all elements from nums[left] to nums[right] equal to nums[right]
            if (right > 0) {
                totalCost += (long long)(nums[right] - nums[right - 1]) * (right - left);
            }
            
            // If totalCost exceeds k, move the left pointer to the right
            while (totalCost > k) {
                totalCost -= (nums[right] - nums[left]);
                ++left;
            }
            
            // Update the maximum frequency
            maxFrequency = max(maxFrequency, right - left + 1);
        }
        
        return maxFrequency;
    }
};

// SLIDING WINDOW METHOD IT IS ANOTHER METHOD IS PREFIX SUM