#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findFactorials(int n) {
        vector<int> factorials; // To store the factorial numbers
        int fact = 1; // Start with 1! which is 1
        int i = 1; // Counter for factorial calculation

        while (fact <= n) {
            factorials.push_back(fact); // Add the current factorial to the list
            i++; // Move to the next integer
            fact *= i; // Calculate the next factorial
        }

        return factorials;
    }
};

int main() {
    Solution sol;
    int n;

    // Input value for n
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> result = sol.findFactorials(n);

    // Output the result
    cout << "Factorials less than or equal to " << n << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
