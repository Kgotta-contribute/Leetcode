#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int arraySum = 0;
        for (int num : nums) {
            arraySum += num;
        }
        return totalSum - arraySum;
    }
};

int main() {
    // Example usage:
    std::vector<int> nums1 = {3, 0, 1};
    std::vector<int> nums2 = {0, 1};
    std::vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    Solution sol;
    int missing1 = sol.missingNumber(nums1);
    int missing2 = sol.missingNumber(nums2);
    int missing3 = sol.missingNumber(nums3);

    // Output results
    std::cout << "Missing number in nums1: " << missing1 << std::endl;
    std::cout << "Missing number in nums2: " << missing2 << std::endl;
    std::cout << "Missing number in nums3: " << missing3 << std::endl;

    return 0;
}
