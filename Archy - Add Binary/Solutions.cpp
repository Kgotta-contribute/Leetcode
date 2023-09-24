#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            result += to_string(sum % 2);
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    string a = "11";
    string b = "1";
    
    Solution solution;
    string sum = solution.addBinary(a, b);
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}
