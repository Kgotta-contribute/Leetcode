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
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }

    int robHelper(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
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




//////////////////////// JAVA ///////////////////////////////



class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        return Math.max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }
    
    private int robHelper(int[] nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = prev1;
            prev1 = Math.max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
}