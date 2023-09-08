#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                std::swap(maxi, mini);
            }
            maxi = std::max(nums[i], maxi * nums[i]);
            mini = std::min(nums[i], mini * nums[i]);
            ans = std::max(ans, maxi);
        }
        return ans;
    }
};

int main() {
    // Test case 1
    std::vector<int> nums1 = {2, 3, -2, 4};
    Solution solution1;
    int result1 = solution1.maxProduct(nums1);
    std::cout << "Test case 1: " << result1 << std::endl;

    // Test case 2
    std::vector<int> nums2 = {-2, 0, -1};
    Solution solution2;
    int result2 = solution2.maxProduct(nums2);
    std::cout << "Test case 2: " << result2 << std::endl;

    return 0;
}
