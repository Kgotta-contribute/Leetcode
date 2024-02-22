class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        // Find the common prefix of left and right
        while (left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }
        // Left shift back to get the final result
        return left << count;
    }
};
