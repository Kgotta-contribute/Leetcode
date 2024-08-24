#include <vector>
using namespace std;

class Solution {
public:
    // Function to compute the GCD using Euclidean algorithm
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to compute both LCM and GCD
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long g = gcd(A, B); // Compute GCD
        
        // Compute LCM using the formula
        // We use (A / g) * B to prevent overflow
        long long lcm = (A / g) * B;
        
        return {lcm, g}; // Return LCM and GCD
    }
};
