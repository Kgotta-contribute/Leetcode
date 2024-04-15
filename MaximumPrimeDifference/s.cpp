#include <vector>
#include <cmath>

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    
    int maximumPrimeDifference(vector<int>& nums) {
        int maxPrimeIndex = -1;
        int minPrimeIndex = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime(nums[i])) {
                maxPrimeIndex = max(maxPrimeIndex, i);
                minPrimeIndex = min(minPrimeIndex, i);
            }
        }
        
        return maxPrimeIndex - minPrimeIndex;
    }
};