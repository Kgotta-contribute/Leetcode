#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) 
        {
            int sum = 0;
            while (n > 0) 
            {
                int digit = n % 10;
                sum = sum + (digit * digit);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
int main() {
    Solution solution;

    int n1 = 19;
    bool result1 = solution.isHappy(n1);
    cout << "Output for Example 1: " << (result1 ? "true" : "false") << endl;

    int n2 = 2;
    bool result2 = solution.isHappy(n2);
    cout << "Output for Example 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}






// JAVA






public class Solution {
    public boolean isHappy(int n) {
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum = sum + (digit * digit);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int n1 = 19;
        boolean result1 = solution.isHappy(n1);
        System.out.println("Output for Example 1: " + (result1 ? "true" : "false"));

        int n2 = 2;
        boolean result2 = solution.isHappy(n2);
        System.out.println("Output for Example 2: " + (result2 ? "true" : "false"));
    }
}

