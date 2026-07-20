// QUESTION : https://leetcode.com/problems/powx-n/


// JAVA

class Solution {
    public double myPow(double x, int n) {
        long num = Math.abs((long) n); // avoid overflow when n = Integer.MIN_VALUE
        
        if (n < 0) {
            x = 1 / x;
        }
        
        double pow = 1.0;
        
        while (num > 0) {
            if ((num & 1) == 1) { // num is odd
                pow *= x;
            }
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
}







// C++
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};






// PYTHON

class Solution:
    def myPow(self, x: float, n: int) -> float: 
        # Edge case: n is zero
        if n == 0:
            return 1.0
        
        # Handle negative exponents
        if n < 0:
            x = 1 / x
            n = -n
        
        result = 1.0
        # Fast exponentiation
        while n > 0:
            if n % 2 == 1:  # If n is odd
                result *= x
            x *= x  # Square the base
            n //= 2  # Reduce n by half
        
        return result