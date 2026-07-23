class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromic
        if (x < 0) {
            return false;
        }

        // Reverse the number and compare with the original
        int original = x;
        long long reversed = 0; // Using long long to handle potential overflow
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Check if the reversed number is equal to the original
        return original == reversed;
    }
};