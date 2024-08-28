#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfDivisors(int N) {
        // Vector to store the sum of divisors for each number from 1 to N
        vector<long long> sumDivisors(N + 1, 0);

        // Iterate over each number from 1 to N
        for (int i = 1; i <= N; ++i) {
            // Add 'i' to all multiples of 'i'
            for (int j = i; j <= N; j += i) {
                sumDivisors[j] += i;
            }
        }

        // Calculate the total sum of all sum of divisors
        long long totalSum = 0;
        for (int i = 1; i <= N; ++i) {
            totalSum += sumDivisors[i];
        }

        return totalSum;
    }
};

int main() {
    Solution sol;
    int N;
    
    cout << "Enter the value of N: ";
    cin >> N;
    
    int result = sol.sumOfDivisors(N);
    cout << "Sum of all divisors from 1 to " << N << " is: " << result << endl;
    
    return 0;
}
