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
    def myPow(self, base: float, n: int) -> float:
        if n == 0:
            return 1.0
        
        power = abs(n)

        if n < 0:
            base = 1 / base
        
        result = 1.0
        
        while power > 0:
            if power & 1:      # if power is odd, Last bit = 1 → power is odd, Last bit = 0 → power is even. power & 1 checks the last bit of the binary representation.
                result *= base
            base *= base            # square the base
            power >>= 1         # halve the exponent, bitwise operator 1010(ie. 10 ) will be made to 101 (ie. 5) fast way to do half. Right shift by one to do half 
        
        return result