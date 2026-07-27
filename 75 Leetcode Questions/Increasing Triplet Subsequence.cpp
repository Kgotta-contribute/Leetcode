// Question -> https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75

// Python 
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first = second = float('inf')
        
        for n in nums:
            if n <= first:
                first = n
            elif n <= second:
                second = n
            else:
                return True
        
        return False





// Java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first  = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for (int n : nums) {
            if (n <= first) {
                first = n;                // best (smallest) first candidate
            } else if (n <= second) {
                second = n;              // best (smallest) second candidate
            } else {
                return true;             // n > second > first → triplet found
            }
        }

        return false;
    }
}