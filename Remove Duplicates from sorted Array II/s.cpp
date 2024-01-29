#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size(); // No duplicates to remove or only one unique element
        }

        int k = 2; // Initialize the result length with the first two elements

        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[k - 1] || nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
