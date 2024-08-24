class Solution {
public:
    int evenlyDivides(int N) {
        int originalNumber = N; // Store the original number for checking divisibility
        int count = 0;
        
        while (N > 0) {
            int digit = N % 10; // Extract the last digit
            N /= 10; // Remove the last digit
            
            if (digit != 0 && originalNumber % digit == 0) {
                count++; // Increment count if digit divides the original number evenly
            }
        }
        
        return count;
    }
};


jdhkfdjhf