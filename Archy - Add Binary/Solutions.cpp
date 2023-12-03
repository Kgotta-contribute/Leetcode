#include <iostream>
#include <algorithm>
using namespace std;
 // little complex because needs more smartness for being efficient otherwise easy
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.length() - 1; // 1
        int j = b.length() - 1;  //0
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            // If you want to convert a character to a integer then use this below line.
            if (i >= 0) {
                // sum is now (0 + '1' - '0') = 1, and i is decremented (i=0)
                sum += a[i] - '0';  //if we have '0' the sum = 48-48 = 0 & if we have '1' the sum = 49-48 = 1 to convert into an integer.
                i--;
            }
            if (j >= 0) {
                // sum is now (1 + '1' - '0') = 2, and j is decremented (j=-1)
                sum += b[j] - '0';
                j--;
            }
            result += to_string(sum % 2); // Append the remainder of sum / 2 (2 % 2 = 0) to result
            carry = sum / 2;  // Update carry to the integer division of sum / 2 (2 / 2 = 1)
        }
        reverse(result.begin(), result.end()); // Reverse the result (0)
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






===================================================================================================================







// JAVA

public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a.charAt(i) - '0';
                i--;
            }
            if (j >= 0) {
                sum += b.charAt(j) - '0';
                j--;
            }
            
            result.append(sum % 2); // Append the remainder of sum / 2 (2 % 2 = 0) to result
            carry = sum / 2; // Update carry to the integer division of sum / 2 (2 / 2 = 1)
        }

        return result.reverse().toString(); // Reverse the result and convert to String
    }

    public static void main(String[] args) {
        String a = "11";
        String b = "1";

        Solution solution = new Solution();
        String sum = solution.addBinary(a, b);

        System.out.println("Sum: " + sum);
    }
}

