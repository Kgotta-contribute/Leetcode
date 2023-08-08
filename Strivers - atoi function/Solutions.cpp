#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string s) {
    int result = 0;
    int sign = 1; // Positive by default
    
    size_t i = 0;
    
    // Remove leading whitespace
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    
    // Handle sign
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    
    // Convert numeric portion
    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';
        
        // Check for integer overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }
        
        result = result * 10 + digit;
        i++;
    }
    
    return result * sign;
}

int main() {
    string input;
    cin >> input;
    
    int result = myAtoi(input);
    cout << "Output: " << result << endl;
    
    return 0;
}
