class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2; // sum of all elements from 1 to n
        int prefix_sum = 0;
        for (int i = 1; i <= n; i++) {
            prefix_sum += i;
            if (prefix_sum == (sum - prefix_sum + i)) { // pivot integer found
                return i;
            }
        }
        return -1; // pivot integer not found
    }
};