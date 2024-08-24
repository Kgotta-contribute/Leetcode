class Solution {
public:
    int reverse(int x) {
        long reversed = 0; // Use long to handle overflow during the reversal process
        int sign = (x > 0) ? 1 : -1; // Determine the sign of x
        x = abs(x); // Work with the absolute value of x
        
        while (x != 0) {
            int digit = x % 10; // Get the last digit
            x /= 10; // Remove the last digit from x
            
            // Check for overflow before it happens
            if (reversed > (INT_MAX - digit) / 10) {
                return 0; // Return 0 in case of overflow
            }
            
            reversed = reversed * 10 + digit; // Append the digit to the reversed number
        }
        
        return reversed * sign; // Apply the original sign
    }
};
