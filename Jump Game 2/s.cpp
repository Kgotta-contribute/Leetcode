#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // Furthest index you can reach
        int steps = 0;    // Number of jumps

        int end = 0; // End of the current range

        for (int i = 0; i < n - 1; ++i) 
        {
            maxReach = max(maxReach, i + nums[i]);
            if (i == end) {
                // Take a jump to the furthest index you can reach in the current range
                end = maxReach;
                steps++;
            }
        }

        return steps;
    }
};
int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << solution.jump(nums1) << endl; // Output: 2

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << solution.jump(nums2) << endl; // Output: 2

    return 0;
}
