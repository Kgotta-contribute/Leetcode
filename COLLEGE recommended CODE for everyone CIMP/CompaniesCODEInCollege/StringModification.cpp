/*String Modification

Problem Statement:
Given a string s, your task is to modify and print the string in a way that adjacent characters don't repeat themselves more than twice. 
You are allowed to delete extra characters to achieve this, and the modified string should be of maximum length. Note that uppercase 
and lowercase characters should be considered different.

Input:
A single line containing the string s.
The string length is between 1 and 103.
The string consists only of lowercase and uppercase English alphabets.
Output:
Print the modified string such that characters don't repeat themselves more than twice.

Example:
Input:
abbbccdeab
Output:
abbccdeab
Explanation:
In the given string, 'b' occurs thrice. To ensure that characters don't repeat more than twice, we omit one occurrence of 'b' and obtain "abbccdeab."

Instructions:
The program should take input from standard input and print output to standard output. Avoid writing additional welcome/greeting messages. The code will be judged by an automated system, and basic test cases will be used initially, followed by more rigorous cases for scoring.
*/


#include <iostream>

using namespace std;

string modifyString(const string& s) {
    string modifiedString;

    int count = 1;  // Initialize count for the first character
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            // If the current character is the same as the previous one, increment the count
            count++;
        } else {
            // If a new character is encountered, reset the count to 1
            count = 1;
        }

        // Append the character to the modified string only if the count is less than or equal to 2
        if (count <= 2) {
            modifiedString += s[i - 1];
        }
    }

    // Append the last character of the input string
    modifiedString += s.back();

    return modifiedString;
}

int main() {
    string inputString;
    
    // Input from standard input
    cin >> inputString;

    // Output to standard output
    cout << modifyString(inputString) << endl;

    return 0;
}





#include <iostream>
#include <string>
using namespace std;

string modifyString(string s) {
    int n = s.length();
    string result = "";
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        int count = 1;
        
        // Count the number of adjacent characters
        while (i < n - 1 && s[i + 1] == ch) {
            count++;
            i++;
        }
        
        // Append the characters to the result string
        if (count >= 2) result += ch;
        if (count >= 3) result += ch;
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    string result = modifyString(s);
    cout << result << endl;
    
    return 0;
}








