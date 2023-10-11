#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        
        // Rob the first house to the second-to-last house
        int max1 = robRange(nums, 0, n - 2);
        
        // Rob the second house to the last house
        int max2 = robRange(nums, 1, n - 1);
        
        return max(max1, max2);
    }
    
    int robRange(vector<int>& nums, int start, int end) {
        int prevMax = 0;
        int currMax = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }
        
        return currMax;
    }
};

int main() {
    vector<int> nums;

    // Input example 1
    nums = {2, 3, 2};
    Solution solution1;
    int maxAmount1 = solution1.rob(nums);
    cout << "Output for example 1: " << maxAmount1 << endl;

    // Input example 2
    nums = {1, 2, 3, 1};
    Solution solution2;
    int maxAmount2 = solution2.rob(nums);
    cout << "Output for example 2: " << maxAmount2 << endl;

    // Input example 3
    nums = {1, 2, 3};
    Solution solution3;
    int maxAmount3 = solution3.rob(nums);
    cout << "Output for example 3: " << maxAmount3 << endl;

    return 0;
}
