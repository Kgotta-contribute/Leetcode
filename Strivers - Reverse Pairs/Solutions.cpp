class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n); // Temporary array for merging
        return mergeSortCount(nums, temp, 0, n - 1);
    }

    int mergeSortCount(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = mergeSortCount(nums, temp, left, mid) + mergeSortCount(nums, temp, mid + 1, right);

        // Counting reverse pairs
        int i = left;
        int j = mid + 1;
        while (i <= mid) {
            while (j <= right && static_cast<long long>(nums[i]) > 2LL * nums[j]) {
                j++;
            }
            count += (j - mid - 1);
            i++;
        }

        // Merge two sorted subarrays
        i = left;
        j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (i = left; i <= right; i++) {
            nums[i] = temp[i];
        }

        return count;
    }
};
