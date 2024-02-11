class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;  // Normalize k to be within array size
        
        if (k == 0) {
            return;  // No rotation needed
        }
        
        reverse(nums, 0, n - 1);     // Reverse the entire array        
        reverse(nums, 0, k - 1);     // Reverse the first K elements  
        reverse(nums, k, n - 1);     // Reverse the remaining N-K elements    
    }
    
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;;
        }
    }
}