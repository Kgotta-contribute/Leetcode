#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};

// int main() {
//     Solution solution;

//     // Example 1
//     std::string s1 = "abc";
//     std::string t1 = "ahbgdc";
//     std::cout << "Example 1: " << std::boolalpha << solution.isSubsequence(s1, t1) << std::endl;

//     // Example 2
//     std::string s2 = "axc";
//     std::string t2 = "ahbgdc";
//     std::cout << "Example 2: " << std::boolalpha << solution.isSubsequence(s2, t2) << std::endl;

//     return 0;
// }
