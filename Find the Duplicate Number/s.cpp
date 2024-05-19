
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // edge case
        if (nums.size() < 2) return -1;
        
        // find the intersection point of the cycle
        int tortoise = nums[0], hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // find the entry point of the cycle
        int ptr1 = nums[0], ptr2 = tortoise;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        
        return ptr1;
    }
};
