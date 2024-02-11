class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0; // Pointers to track the subarray
        int zeroCount = 0; // Counter for zeros in the current subarray
        int maxLen = 0; // Length of the longest subarray with at most k zeros

        while (right < n) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) { // Shrink the subarray from the left
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++; // Expand the subarray from the right
        }

        return maxLen;
    }
};