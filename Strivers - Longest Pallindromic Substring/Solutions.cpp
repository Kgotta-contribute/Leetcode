#include <iostream>
#include <string>

std::string longestPalindrome(const std::string& s) {
    int n = s.length();
    if (n <= 1) {
        return s;
    }

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; ++i) {
        // Check for odd length palindromes
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }

        // Check for even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    std::string s1 = "babad";
    std::string s2 = "cbbd";

    std::string result1 = longestPalindrome(s1);
    std::string result2 = longestPalindrome(s2);

    std::cout << "Output for Example 1: " << result1 << std::endl;
    std::cout << "Output for Example 2: " << result2 << std::endl;

    return 0;
}
